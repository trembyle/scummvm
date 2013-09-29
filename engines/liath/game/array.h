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

#ifndef LIATH_ARRAY_H
#define LIATH_ARRAY_H

#include "liath/shared.h"

namespace Liath {

class LiathEngine;

class ArrayManager {
public:

	ArrayManager(LiathEngine *engine);
	~ArrayManager();

	OpcodeRet opcodeInit(OpcodeParameters *parameters);
	OpcodeRet opcodeImg(OpcodeParameters *parameters);
	OpcodeRet opcodeAdd(OpcodeParameters *parameters);
	OpcodeRet opcodeDelete(OpcodeParameters *parameters);
	OpcodeRet opcodeKill(OpcodeParameters *parameters);
	OpcodeRet opcodeClear(OpcodeParameters *parameters);
	OpcodeRet opcodeGet(OpcodeParameters *parameters);
	OpcodeRet opcodeGetNumber(OpcodeParameters *parameters);
	OpcodeRet opcodeSize(OpcodeParameters *parameters);
	OpcodeRet opcodeTget(OpcodeParameters *parameters);
	OpcodeRet opcodeCurrent(OpcodeParameters *parameters);
	OpcodeRet opcodeSetCurrent(OpcodeParameters *parameters);
	OpcodeRet opcodeGetScroll(OpcodeParameters *parameters);

private:
	LiathEngine* _engine;

	// Array storage
	Array _data[10];

	Array *getFirstEmptyArray();
};

} // End of namespace Liath

#endif // LIATH_ARRAY_H
