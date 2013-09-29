/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include "liath/game/interpreter.h"

#include "liath/data/segment.h"

#include "liath/game/action.h"
#include "liath/game/array.h"
#include "liath/game/expression.h"
#include "liath/game/game.h"
#include "liath/game/graphics.h"
#include "liath/game/hero.h"
#include "liath/game/mouse.h"
#include "liath/game/position.h"
#include "liath/game/progress.h"
#include "liath/game/savegame.h"
#include "liath/game/sound.h"
#include "liath/game/text.h"
#include "liath/game/work.h"

#include "liath/liath.h"
#include "liath/helpers.h"

namespace Liath {

// Name of all opcodes
const char *g_opcodes[] = {
	"None",
	"1",
	"Key",
	"MyRandom",
	"4",
	"5",                         // 5
	"6",
	"7",
	"8",
	"9",
	"10",                        // 10
	"11",
	"12",
	"13",
	"14",
	"15",                        // 15
	"16",
	"HeroVar",
	"HeroSys",
	"Var",
	"Sys",                       // 20
	"Global",
	"Expression",
	"Cel",
	"CelExt",
	"25",                        // 25
	"26",
	"27",
	"28",
	"29",
	"Look",                      // 30
	"Pers",
	"Dist",
	"PassVar",
	"ExitGame",
	"ExitHero",                  // 35
	"36",
	"37",
	"38",
	"39",
	"40",                        // 40
	"41",
	"42",
	"43",
	"CurAction",
	"StartAction",               // 45
	"StartActionGlobal",
	"StartActionHeroVar",
	"StartActionVar",
	"StartObject",
	"StartObject2",              // 50
	"StartObject3",
	"StartObject4",
	"StartHero",
	"StartHeroExt",
	"ResetHero",                 // 55
	"56",
	"57",
	"58",
	"59",
	"60",                        // 60
	"61",
	"62",
	"63",
	"64",
	"65",                        // 65
	"66",
	"67",
	"68",
	"69",
	"70",                        // 70
	"71",
	"72",
	"73",
	"74",
	"75",                        // 75
	"76",
	"77",
	"78",
	"79",
	"80",                        // 80
	"81",
	"Unfreeze",
	"Unfreeze2",
	"UnfreezeGlobal",
	"UnfreezeHeroVar",           // 85
	"UnfreezeVar",
	"Freeze",
	"Freeze2",
	"FreezeGlobal",
	"FreezeHeroVar",             // 90
	"FreezeVar",
	"Stop",
	"Stop2",
	"StopGlobal",
	"StopHeroVar",              // 95
	"StopVar",
	"Continue",
	"Continue2",
	"ContinueGlobal",
	"ContinueHeroVar",           // 100
	"ContinueVar",
	"102",
	"103",
	"104",
	"105",                        // 105
	"106",
	"107",
	"108",
	"109",
	"110",                        // 110
	"111",
	"112",
	"113",
	"114",
	"115",                        // 115
	"116",
	"117",
	"118",
	"119",
	"120",                        // 120
	"121",
	"122",
	"123",
	"124",
	"125",                        // 125
	"126",
	"127",
	"128",
	"129",
	"130",                        // 130
	"131",
	"132",
	"133",
	"134",
	"135",                        // 135
	"QuitHero",
	"QuitGlobal",
	"QuitHeroVar",
	"QuitVar",
	"HeroVarGlobal",             // 140
	"HeroVarHeroVar",
	"HeroVarVar",
	"PlayWave",
	"PlayMidi",
	"PlayMidiLoop",              // 145
	"StopMidi",
	"AutoStart",
	"AutoStop",
	"149",
	"150",                       // 150
	"Auto2Hero",
	"152",
	"Auto2HeroGlobal",
	"Auto2HeroHeroVar",
	"Auto2HeroVar",              // 155
	"Barrier",
	"157",
	"HearGlobal",
	"HearHeroVar",
	"HearVar",                   // 160
	"161",
	"Face2Hero",
	"Face2HeroGlobal",
	"Face2HeroHeroVar",
	"Face2HeroVar",              // 165
	"HPers",
	"Feel",
	"Barrier2",
	"Barrier3",
	"170",                       // 170
	"171",
	"SaveTop",
	"EndTop",
	"GlassIncrement",
	"GlassDecrement",            // 175
	"TypeMouse",
	"KeyMouse",
	"Bkey",
	"AutoCheck",
	"Barrier4",                  // 180
	"AddMouseBox",
	"PushMouse",
	"PopMouse",
	"Redraw",
	"PushHerous",                // 185
	"PopHerous",
	"HTime",
	"PlayAvsStopMusic",
	"DelMouseBox",
	"PlayMusic",                 // 190
	"StopMusic",
	"CommandNumberBox",
	"Cash",
	"194",
	"SaveGame",                  // 195
	"LoadGame",
	"TextOut",
	"TextQuit",
	"TextExit",
	"TextChange",                // 200
	"PlayAvs",
	"SaveHero",
	"LoadHero",
	"NumberAct",
	"TextCheck",                 // 205
	"ArrayInit",
	"ArrayAdd",
	"ArrayDel",
	"ArrayKill",
	"ArrayClear",                // 210
	"ArrayGet",
	"ArraySize",
	"ArrayTGet",
	"ArrayCur",
	"ArraySetCur",               // 215
	"ArrayGetScroll",
	"HDark",
	"ArrayImg",
	"CheckLimits",
	"XScroll",                   // 220
	"YScroll",
	"CheckMouse",
	"MousePress",
	"SetBg",
	"SetHeroRGB",                // 225
	"ArrayGetNumber",
	"ResetMouse",
	"MouseScroll",
	"VolMusic",
	"GStopMusic",                // 230
	"PlayMusicEffects",
	"ProgressInit ",
	"ProgressSet",
	"ProgressGet",
	"ProgressHelp",              // 235
	"Restart"
};

#define OPCODE_NAME(opcode) (opcode > 237 ? Common::String::format("%d", opcode).c_str() : g_opcodes[opcode])

Interpreter::Interpreter(LiathEngine *engine) : _engine(engine) {}

Interpreter::~Interpreter() {
	// Zero-out passed pointers
	_engine = NULL;
}

//////////////////////////////////////////////////////////////////////////
// Interpreter
//////////////////////////////////////////////////////////////////////////
int Interpreter::interpret(ObjectIndex *pObjectIndex, Segment segment) const {
	getSegment()->set(kSegmentExpression, segment);

	while (pObjectIndex) {

		ObjectIndex objectIndex = *pObjectIndex;
		OpcodeParameters *parameters = (objectIndex ? (OpcodeParameters *)getSegment()->getData(kSegmentExpression, objectIndex) : NULL);

		if (parameters) {

			for (;;) {
				switch (run(parameters, objectIndex)) {
				default:
				case kOpcodeRetDefault:
					objectIndex = parameters->objectIndex;
					parameters = (objectIndex ? (OpcodeParameters *)getSegment()->getData(kSegmentExpression, objectIndex) : NULL);

					if (!parameters)
						goto update_index;
					break;

				case kOpcodeRetNext:
					if (pObjectIndex[2])
						pObjectIndex = (pObjectIndex[2] ? (ObjectIndex *)getSegment()->getData(kSegmentExpression, pObjectIndex[2]) : NULL);
					else
						goto update_index;
					break;

				case kOpcodeRetExit:
					return 0;

				case kOpcodeRetExitSuccess:
				case kOpcodeRetExitSuccess2:
					return 2;
				}
			}
		} else {
update_index:
			if (pObjectIndex[3])
				pObjectIndex = (ObjectIndex *)getSegment()->getData(kSegmentExpression, pObjectIndex[3]);
			else if (pObjectIndex[1])
				pObjectIndex = (ObjectIndex *)getSegment()->getData(kSegmentExpression, pObjectIndex[1]);
			else
				pObjectIndex = NULL;
		}
	}

	return 1;
}

OpcodeRet Interpreter::run(OpcodeParameters *parameters, ObjectIndex index) const {
	debugC(kLiathDebugInterpreter, "Executing opcode: %s (%02d)", OPCODE_NAME(parameters->opcode), parameters->opcode);

	switch (parameters->opcode) {
	default:
		return kOpcodeRetDefault;

	case kOpcodeStartHero:
		return getHero()->opcodeStart(parameters, NULL, NULL);

	case kOpcodeResetHero:
		return getHero()->opcodeReset(parameters, NULL);

	case kOpcodeStartHeroExt:
		return getHero()->opcodeStartHeroExt(parameters);

	case kOpcodeStartAction:
		return getAction()->opcodeStart(parameters);

	case kOpcodeStartActionGlobal:
		return getAction()->opcodeStartGlobal(parameters);

	case kOpcodeStartActionHeroVar:
		return getAction()->opcodeStartHeroVariable(parameters);

	case kOpcodeStartActionVar:
		return getAction()->opcodeStartVariable(parameters);

	case kOpcodeCheckLimits:
		return getPosition()->opcodeCheckLimits(parameters);

	case kOpcodeStartObject:
	case kOpcodeStartObject2:
	case kOpcodeStartObject3:
	case kOpcodeStartObject4:
		return getWork()->opcodeStartObject(index);

	case kOpcodeCommandNumberBox:
		return getMouse()->opcodeCommandNumberBox(parameters);

	case kOpcodePassVar:
		return getHero()->opcodePassVariable(parameters);

	case kOpcodeExitGame:
		return getAction()->opcodeExitGame(parameters);

	case kOpcodeRestart:
		return getWork()->opcodeRestart();

	case kOpcodeExitHero:
		return getHero()->opcodeExitHero(parameters);

	case kOpcodeCel:
		return getWork()->opcodeCel(parameters);

	case kOpcodeCelExt:
		return getWork()->opcodeCelExt(parameters);

	case kOpcodeMyRandom:
		return getGame()->opcodeRandom(parameters);

	case kOpcodeCash:
		return getSound()->opcodeCash(parameters);

	case kOpcodeSaveGame:
		return getSave()->opcodeSave(parameters);

	case kOpcodeLoadGame:
		return getSave()->opcodeLoad(parameters);

	case kOpcodeSaveHero:
		return getHero()->opcodeSave(parameters);

	case kOpcodeLoadHero:
		return getHero()->opcodeLoad();

	case kOpcodeNumberAct:
		return getAction()->opcodeNumber(parameters);

	case kOpcodeRedraw:
		return getGraphics()->opcodeRedraw(parameters);

	case kOpcodeAddMouseBox:
		return getMouse()->opcodeAddBox(parameters);

	case kOpcodeDelMouseBox:
		return getMouse()->opcodeRemoveBox(parameters);

	case kOpcodePushMouse:
		return getMouse()->opcodePush();

	case kOpcodePopMouse:
		return getMouse()->opcodePop();

	case kOpcodePopHeros:
		return getWork()->opcodePopHeros();

	case kOpcodePushHeros:
		return getWork()->opcodePushHeros();

	case kOpcodeTypeMouse:
		return getMouse()->opcodeType(parameters);

	case kOpcodeResetMouse:
		return getMouse()->opcodeReset(parameters);

	case kOpcodeKeyMouse:
		return getMouse()->opcodeKey(parameters);

	case kOpcodeMousePress:
		return getMouse()->opcodePress(parameters);

	case kOpcodeTextOut:
		return getText()->opcodeOut(parameters);

	case kOpcodeTextQuit:
		return getText()->opcodeQuit(parameters);

	case kOpcodeTextExit:
		return getText()->opcodeExitText(parameters);

	case kOpcodeTextCheck:
		return getText()->opcodeCheck(parameters);

	case kOpcodeTextChange:
		return getText()->opcodeChange(parameters);

	case kOpcodeArrayInit:
		return getArray()->opcodeInit(parameters);

	case kOpcodeArrayImg:
		return getArray()->opcodeImg(parameters);

	case kOpcodeArrayAdd:
		return getArray()->opcodeAdd(parameters);

	case kOpcodeArrayDelete:
		return getArray()->opcodeDelete(parameters);

	case kOpcodeArrayKill:
		return getArray()->opcodeKill(parameters);

	case kOpcodeArrayClear:
		return getArray()->opcodeClear(parameters);

	case kOpcodeArrayGet:
		return getArray()->opcodeGet(parameters);

	case kOpcodeArrayGetNumber:
		return getArray()->opcodeGetNumber(parameters);

	case kOpcodeArraySize:
		return getArray()->opcodeSize(parameters);

	case kOpcodeArrayTGet:
		return getArray()->opcodeTget(parameters);

	case kOpcodeArrayCurrent:
		return getArray()->opcodeCurrent(parameters);

	case kOpcodeArraySetCurrent:
		return getArray()->opcodeSetCurrent(parameters);

	case kOpcodeHeroTime:
		return getWork()->opcodeHeroTime(parameters);

	case kOpcodeHeroDark:
		return getWork()->opcodeHeroDark(parameters);

	case kOpcodeXScroll:
		return getGraphics()->opcodeXScroll(parameters);

	case kOpcodeYScroll:
		return getGraphics()->opcodeYScroll(parameters);

	case kOpcodePlayAvsStopMusic:
		return getGraphics()->opcodePlayAvs(parameters, false);

	case kOpcodePlayAvs:
		return getGraphics()->opcodePlayAvs(parameters, true);

	case kOpcodeFreeze:
	case kOpcodeFreeze2:
		return getHero()->opcodeFreeze(parameters);

	case kOpcodeFreezeGlobal:
		return getHero()->opcodeFreezeGlobal(parameters);

	case kOpcodeFreezeHeroVar:
		return getHero()->opcodeFreezeHeroVar(parameters);

	case kOpcodeFreezeVar:
		return getHero()->opcodeFreezeVar(parameters);

	case kOpcodeUnfreeze:
	case kOpcodeUnfreeze2:
		return getHero()->opcodeUnfreeze(parameters);

	case kOpcodeUnfreezeGlobal:
		return getHero()->opcodeUnfreezeGlobal(parameters);

	case kOpcodeUnfreezeHeroVar:
		return getHero()->opcodeUnfreezeHeroVar(parameters);

	case kOpcodeUnfreezeVar:
		return getHero()->opcodeUnfreezeVar(parameters);

	case kOpcodeStop:
	case kOpcodeStop2:
		return getWork()->opcodeStop(parameters);

	case kOpcodeStopGlobal:
		return getWork()->opcodeStopGlobal(parameters);

	case kOpcodeStopHeroVar:
		return getWork()->opcodeStopHeroVar(parameters);

	case kOpcodeStopVar:
		return getWork()->opcodeStopVar(parameters);

	case kOpcodeContinue:
	case kOpcodeContinue2:
		return getWork()->opcodeContinue(parameters);

	case kOpcodeContinueGlobal:
		return getWork()->opcodeContinueGlobal(parameters);

	case kOpcodeContinueHeroVar:
		return getWork()->opcodeContinueHeroVar(parameters);

	case kOpcodeContinueVar:
		return getWork()->opcodeContitnueVar(parameters);

	case kOpcodeKey:
		return getGame()->opcodeKey(parameters);

	case kOpcodeBkey:
		return getGame()->opcodeBKey(parameters);

	case kOpcodeCurrentAction:
		return getAction()->opcodeCurrentAction(parameters);

	case kOpcodeHeroVarGlobal:
		return getHero()->opcodeHeroVarGlobal(parameters);

	case kOpcodeHeroVarHeroVar:
		return getHero()->opcodeHeroVarHeroVar(parameters);

	case kOpcodeHeroVarVar:
		return getHero()->opcodeHeroVarVar(parameters);

	case kOpcodeHeroVar:
		return getHero()->opcodeHeroVar(parameters);

	case kOpcodeHeroSys:
		return getHero()->opcodeHeroSys(parameters);

	case kOpcodeVar:
		return getHero()->opcodeVar(parameters);

	case kOpcodeSys:
		return getHero()->opcodeSys(parameters);

	case kOpcodeGlobal:
		return getGame()->opcodeGlobal(parameters);

	case kOpcodeExpression:
		return getExpression()->opcodeExpression(parameters);

	case kOpcodeQuitHero:
		return getHero()->opcodeQuitHero(parameters);

	case kOpcodeQuitGlobal:
		return getHero()->opcodeQuitGlobal(parameters);

	case kOpcodeQuitHeroVar:
		return getHero()->opcodeQuitHeroVar(parameters);

	case kOpcodeQuitVar:
		return getHero()->opcodeQuitVar(parameters);

	case kOpcodeCheckMouse:
		return getMouse()->opcodeCheck(parameters);

	case kOpcodeLook:
		return getGraphics()->opcodeLook(parameters);

	case kOpcodePers:
		return getPosition()->opcodePers(parameters);

	case kOpcodeHeroPers:
		return getPosition()->opcodeHeroPers(parameters);

	case kOpcodeDist:
		return getPosition()->opcodeDist(parameters);

	case kOpcodeFeel:
		return getPosition()->opcodeFeel(parameters);

	case kOpcodeGlassIncrement:
		return getWork()->opcodeGlass(parameters, true);

	case kOpcodeGlassDecrement:
		return getWork()->opcodeGlass(parameters, false);

	case kOpcodePlayWave:
		return getSound()->opcodePlayWave(parameters);

	case kOpcodePlayMusic:
		return getSound()->opcodePlayMusic(parameters, false);

	case kOpcodePlayMusicEffects:
		return getSound()->opcodePlayMusic(parameters, true);

	case kOpcodeStopMusic:
		return getSound()->opcodeStopMusic(parameters);

	case kOpcodeGlobalStopMusic:
		return getSound()->opcodeGlobalStopMusic(parameters);

	case kOpcodePlayMidi:
		return getSound()->opcodePlayMidi(parameters, false);

	case kOpcodePlayMidiLoop:
		return getSound()->opcodePlayMidi(parameters, true);

	case kOpcodeStopMidi:
		return getSound()->opcodeStopMidi();

	case kOpcodeAutoStart:
		return getPosition()->opcodeAutoStart(parameters);

	case kOpcodeAutoCheck:
		return getPosition()->opcodeAutoCheck(parameters);

	case kOpcodeAutoStop:
		return getPosition()->opcodeAutoStop(parameters);

	case kOpcodeSetBg:
		return getGraphics()->opcodeSetBackground(parameters);

	case kOpcodeSetHeroRGB:
		return getGraphics()->opcodeSetHeroRGB(parameters);

	case kOpcodeProgressInit:
		return getProgress()->opcodeInit(parameters);

	case kOpcodeProgressSet:
		return getProgress()->opcodeSet(parameters);

	case kOpcodeProgressGet:
		return getProgress()->opcodeGet(parameters);

	case kOpcodeProgressHelp:
		return getProgress()->opcodeHelp(parameters);

	case kOpcodeAuto2Hero:
		return getHero()->opcodeAuto2Hero(parameters);

	case kOpcodeAuto2HeroGlobal:
		return getHero()->opcodeAuto2HeroGlobal(parameters);

	case kOpcodeAuto2HeroHeroVar:
		return getHero()->opcodeAuto2HeroHeroVar(parameters);

	case kOpcodeAuto2HeroVar:
		return getHero()->opcodeAuto2HeroVar(parameters);

	case kOpcodeBarrier:
	case kOpcodeBarrier2:
	case kOpcodeBarrier3:
	case kOpcodeBarrier4:
		return getPosition()->opcodeBarrier(parameters);

	case kOpcodeHearGlobal:
		return getHero()->opcodeHearGlobal(parameters);

	case kOpcodeHearHeroVar:
		return getHero()->opcodeHearHeroVar(parameters);

	case kOpcodeHearVar:
		return getHero()->opcodeHearVar(parameters);

	case kOpcodeArrayGetScroll:
		return getArray()->opcodeGetScroll(parameters);

	case kOpcodeFace2Hero:
		return getHero()->opcodeFace2Hero(parameters);

	case kOpcodeFace2HeroGlobal:
		return getHero()->opcodeFace2HeroGlobal(parameters);

	case kOpcodeFace2HeroHeroVar:
		return getHero()->opcodeFace2HeroHeroVar(parameters);

	case kOpcodeFace2HeroVar:
		return getHero()->opcodeFace2HeroVar(parameters);

	case kOpcodeSaveTop:
		return getWork()->opcodeSavetop(parameters);

	case kOpcodeEndTop:
		return getWork()->opcodeSendtop();

	case kOpcodeMouseScroll:
		return getMouse()->opcodeScroll(parameters);

	case kOpcodeVolMusic:
		return getSound()->opcodeVolume(parameters);
	}
}

} // End of namespace Liath
