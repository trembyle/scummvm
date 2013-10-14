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

#ifndef LIATH_MESSAGE_H
#define LIATH_MESSAGE_H

#include "liath/shared.h"

namespace Common {
	class File;
}

namespace Liath {

class LiathEngine;

class MessageManager {
public:
	struct Message {
		uint16 field_0;
		uint16 index;
		uint16 field_4;
		uint16 field_6;
		uint16 field_8;
		uint16 field_A;
		uint32 progressTextLength;
		byte field_10;
		byte field_11;
		uint32 field_12;
		char field_16[31];
		char field_35[31];
		uint16 field_54;
		uint16 field_56;
		byte messagesCount;
		uint32 messageIndex;
		uint32 field_5D[20];
		uint16 field_AD;
		bool noStop;
		byte field_B0;
		byte field_B1;
		byte field_B2;
		bool isInternationalLanguage;

		Message() {
			field_0 = 0;
			index = 0;
			field_4 = 0;
			field_6 = 0;
			field_8 = 0;
			field_A = 0;
			progressTextLength = 0;
			field_10 = 0;
			field_11 = 0;
			field_12 = 0;
			memset(field_16, 0, sizeof(field_16));
			memset(field_35, 0, sizeof(field_35));
			field_54 = 0;
			field_56 = 0;
			messagesCount = 0;
			messageIndex = 0;
			memset(field_5D, 0, sizeof(field_5D));
			field_AD = 0;
			noStop = false;
			field_B0 = 0;
			field_B1 = 0;
			field_B2 = 0;
			isInternationalLanguage = false;
		}

		void load(Common::File *file);
	};

	struct MessageAction {
		int16 index;
		Common::String name;

		MessageAction() {
			index = 0;
		}

		void reset() {
			index = 0;
			name = "";
		}

		void load(Common::File *file);
	};

	MessageManager(LiathEngine *engine);
	~MessageManager();

	bool readMessage(uint32 *index, Message *message);
	bool readAction(uint32 index, MessageAction *message);

private:
	LiathEngine* _engine;

	MessageAction _action;
};

} // End of namespace Liath

#endif // LIATH_MESSAGE_H
