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

#ifndef LIATH_MOUSEMANAGER_H
#define LIATH_MOUSEMANAGER_H

#include "liath/shared.h"

#include "common/array.h"

namespace Liath {

class LiathEngine;

class MouseManager {
public:

	MouseManager(LiathEngine *engine);
	~MouseManager();

	void unload();

	// Opcodes
	OpcodeRet opcodeCommandNumberBox(OpcodeParameters *parameters);
	OpcodeRet opcodePush();
	OpcodeRet opcodePop();
	OpcodeRet opcodeType(OpcodeParameters *parameters);
	OpcodeRet opcodeReset(OpcodeParameters *parameters);
	OpcodeRet opcodeKey(OpcodeParameters *parameters);
	OpcodeRet opcodePress(OpcodeParameters *parameters);
	OpcodeRet opcodeScroll(OpcodeParameters *parameters);
	OpcodeRet opcodeCheck(OpcodeParameters *parameters);
	OpcodeRet opcodeAddBox(OpcodeParameters *parameters);
	OpcodeRet opcodeRemoveBox(OpcodeParameters *parameters);

private:
	LiathEngine* _engine;

	int32 _count;
	bool _pressMouse;
	int _countStopMouse;
	int _timeCountStopMouse;

	Common::Array<MouseBox *> _boxes;

	uint32 numberBox(uint32 param1, uint32 param2);

};

} // End of namespace Liath

#endif // LIATH_MOUSEMANAGER_H
