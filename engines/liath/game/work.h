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

#ifndef LIATH_WORKMANAGER_H
#define LIATH_WORKMANAGER_H

#include "liath/shared.h"

#include "common/array.h"

namespace Liath {

class LiathEngine;

class WorkManager {
public:

	WorkManager(LiathEngine *engine);
	~WorkManager();

	void unload();

	// Opcodes
	OpcodeRet opcodeStartObject(ObjectIndex index);
	OpcodeRet opcodeCel(OpcodeParameters *parameters);
	OpcodeRet opcodeCelExt(OpcodeParameters *parameters);
	OpcodeRet opcodeHeroTime(OpcodeParameters *parameters);
	OpcodeRet opcodeHeroDark(OpcodeParameters *parameters);
	OpcodeRet opcodeRestart();
	OpcodeRet opcodePopHeros();
	OpcodeRet opcodePushHeros();
	OpcodeRet opcodeGlass(OpcodeParameters *parameters, bool doIncrement);
	OpcodeRet opcodeStop(OpcodeParameters *parameters);
	OpcodeRet opcodeStopGlobal(OpcodeParameters *parameters);
	OpcodeRet opcodeStopHeroVar(OpcodeParameters *parameters);
	OpcodeRet opcodeStopVar(OpcodeParameters *parameters);
	OpcodeRet opcodeContinue(OpcodeParameters *parameters);
	OpcodeRet opcodeContinueGlobal(OpcodeParameters *parameters);
	OpcodeRet opcodeContinueHeroVar(OpcodeParameters *parameters);
	OpcodeRet opcodeContitnueVar(OpcodeParameters *parameters);
	OpcodeRet opcodeSavetop(OpcodeParameters *parameters);
	OpcodeRet opcodeSendtop();

	Work *getCurrent() { return _currentWork; }
	Work *get(HeroIndex index);
	Work *getFromTextIndex(int32 index);

	void setWorkInfo(WorkInfo *info) { _info = info; }
	WorkInfo *getWorkInfo() { return _info; }

	// Helpers
	void resetField_E00();
	Work *seWork(Work* current);

private:
	LiathEngine* _engine;

	Work* _currentWork;
	WorkInfo *_info;

	Common::Array<Work *> _works;
};

} // End of namespace Liath

#endif // LIATH_WORKMANAGER_H
