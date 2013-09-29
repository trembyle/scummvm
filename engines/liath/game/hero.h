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

#ifndef LIATH_HERO_H
#define LIATH_HERO_H

#include "liath/shared.h"

#include "common/array.h"

namespace Liath {

class LiathEngine;

class HeroManager {
public:
	HeroManager(LiathEngine *engine);
	~HeroManager();

	void opcodeLoad(uint32 count, size_t size);
	void unload();

	// Opcodes
	OpcodeRet opcodeStart(OpcodeParameters *parameters, Work **pWork, WorkData *data);
	OpcodeRet opcodeStartHeroExt(OpcodeParameters *parameters);
	OpcodeRet opcodeReset(OpcodeParameters *parameters, void *unkown);
	OpcodeRet opcodeExitHero(OpcodeParameters *parameters);
	OpcodeRet opcodeSave(OpcodeParameters *parameters);
	OpcodeRet opcodeLoad();
	OpcodeRet opcodePassVariable(OpcodeParameters *parameters);
	OpcodeRet opcodeFreeze(OpcodeParameters *parameters);
	OpcodeRet opcodeFreezeGlobal(OpcodeParameters *parameters);
	OpcodeRet opcodeFreezeHeroVar(OpcodeParameters *parameters);
	OpcodeRet opcodeFreezeVar(OpcodeParameters *parameters);
	OpcodeRet opcodeUnfreeze(OpcodeParameters *parameters);
	OpcodeRet opcodeUnfreezeGlobal(OpcodeParameters *parameters);
	OpcodeRet opcodeUnfreezeHeroVar(OpcodeParameters *parameters);
	OpcodeRet opcodeUnfreezeVar(OpcodeParameters *parameters);
	OpcodeRet opcodeHeroVar(OpcodeParameters *parameters);
	OpcodeRet opcodeHeroVarGlobal(OpcodeParameters *parameters);
	OpcodeRet opcodeHeroVarHeroVar(OpcodeParameters *parameters);
	OpcodeRet opcodeHeroVarVar(OpcodeParameters *parameters);
	OpcodeRet opcodeHeroSys(OpcodeParameters *parameters);
	OpcodeRet opcodeVar(OpcodeParameters *parameters);
	OpcodeRet opcodeSys(OpcodeParameters *parameters);
	OpcodeRet opcodeQuitHero(OpcodeParameters *parameters);
	OpcodeRet opcodeQuitGlobal(OpcodeParameters *parameters);
	OpcodeRet opcodeQuitHeroVar(OpcodeParameters *parameters);
	OpcodeRet opcodeQuitVar(OpcodeParameters *parameters);
	OpcodeRet opcodeAuto2Hero(OpcodeParameters *parameters);
	OpcodeRet opcodeAuto2HeroGlobal(OpcodeParameters *parameters);
	OpcodeRet opcodeAuto2HeroHeroVar(OpcodeParameters *parameters);
	OpcodeRet opcodeAuto2HeroVar(OpcodeParameters *parameters);
	OpcodeRet opcodeFace2Hero(OpcodeParameters *parameters);
	OpcodeRet opcodeFace2HeroGlobal(OpcodeParameters *parameters);
	OpcodeRet opcodeFace2HeroHeroVar(OpcodeParameters *parameters);
	OpcodeRet opcodeFace2HeroVar(OpcodeParameters *parameters);
	OpcodeRet opcodeHearGlobal(OpcodeParameters *parameters);
	OpcodeRet opcodeHearHeroVar(OpcodeParameters *parameters);
	OpcodeRet opcodeHearVar(OpcodeParameters *parameters);

	// Utils
	void create(Hero *hero, byte *data1, byte *data2, byte *data3, byte *data4);
	void remove(HeroIndex index);

	// Accessors
	Hero *get(HeroIndex index);
	uint32 getData(HeroIndex index, uint32 offset) { return get(index)->getData(offset); }
	void setData(HeroIndex index, uint32 offset, int32 val) { get(index)->setData(offset, (uint32)val); }

private:
	struct OpcodeParametersHero {
		uint32 objectIndex;
		byte opcode;
		byte test;
		byte params[80];

		OpcodeParametersHero() {
			objectIndex = 0;
			opcode = 0;
			test = 0;
			memset(&params, 0, 80);
		}

		uint32 getDword(uint32 offset) {
			return READ_UINT32(&params + offset);
		}

		void setDword(uint32 offset, uint32 val) {
			WRITE_UINT32(&params + offset, val);
		}

		void setByte(uint32 offset, byte val) {
			*(byte *)(&params + offset) = val;
		}
	};

	LiathEngine* _engine;

	// Storage
	Common::Array<Hero *> _heros;
	void *_storage;

	// Current saved hero
	OpcodeParametersHero _heroParams;

	// "Global" variables
	uint32 _nHero;

	// Opcode helpers
	OpcodeRet opcodeFreeze(HeroIndex heroIndex);
	OpcodeRet quit(HeroIndex heroIndex);
	OpcodeRet auto2(OpcodeParameters *parameters);
	OpcodeRet hear(OpcodeParameters *parameters);
};

} // End of namespace Liath

#endif // LIATH_HERO_H.....
