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

#include "liath/data/message.h"

#include "liath/game/progress.h"
#include "liath/game/text.h"

#include "liath/helpers.h"
#include "liath/liath.h"

#include "common/file.h"

namespace Liath {

//////////////////////////////////////////////////////////////////////////
/// Message / MessageAction
//////////////////////////////////////////////////////////////////////////
void MessageManager::Message::load(Common::File *file) {
	this->field_0 = file->readUint16LE();
	this->index   = file->readUint16LE();
	this->field_4 = file->readUint16LE();
	this->field_6 = file->readUint16LE();
	this->field_8 = file->readUint16LE();
	this->field_A = file->readUint16LE();
	this->progressTextLength = file->readUint32LE();
	this->field_10 = file->readByte();
	this->field_11 = file->readByte();
	this->field_12 = file->readUint32LE();
	file->read(&this->field_16, 31);
	file->read(&this->field_35, 31);
	this->field_54 = file->readUint16LE();
	this->field_56 = file->readUint16LE();

	for (uint i = 0; i < sizeof(field_5D); i++)
		field_5D[i] = file->readUint32LE();

	this->field_AD = file->readUint16LE();
	this->noStop = file->readByte();
	this->field_B0 = file->readByte();
	this->field_B1 = file->readByte();
	this->field_B2 = file->readByte();
	this->isInternationalLanguage = file->readByte();
}

void MessageManager::MessageAction::load(Common::File *file) {
	this->index = file->readUint16LE();
	/*uint16 size = */file->readUint16LE();
	char buffer[301];
	file->read(&buffer, sizeof(buffer));

	name = Common::String(buffer);
}

//////////////////////////////////////////////////////////////////////////
/// MessageManager
//////////////////////////////////////////////////////////////////////////
MessageManager::MessageManager(LiathEngine *engine) : _engine(engine) {}

MessageManager::~MessageManager() {
	// Zero-out passed pointers
	_engine = NULL;
}

bool MessageManager::readMessage(uint32 *pIndex, Message *pMessage) {
	int index = *pIndex;

	if (index <= 30000 || index >= 30011) {
		if (index < 1)
			return false;

		// Open message.dat
		Common::File *file = new Common::File();
		if (!file->open("message.dat")) {
			delete file;
			return false;
		}

		file->seek(index * 180, SEEK_SET);

		Message message;
		message.load(file);

		if (message.field_0 == 4660 && message.index == index) {
			delete file;
		} else {
			file->seek(4999 * 180);
			if (file->eos())
				return false;

			message.load(file);

			delete file;
			if (message.field_0 != 4660 || message.index != 4999)
				return false;

			*pIndex = 4999;
		}

		getText()->setNoStop(message.noStop);

		if (message.field_B2 == 1) {
			error("ResourceManager::readMessage: Not implemented!");
		}

		// Copy message data
		memcpy(pMessage, &message, sizeof(message));

		debugC(2, kLiathDebugResource, "Loaded message at index %d", message.index);

		return true;
	}

	// Read message from saved data
	error("ResourceManager::readMessage: Not implemented!");

	return true;
}

bool MessageManager::readAction(uint32 index, MessageAction *message) {
	// Open message.str
	Common::File *file = new Common::File();
	if (!file->open("message.str")) {
		delete file;
		return false;
	}

	// Read message entry
	file->seek(index * 305);

	message->load(file);

	delete file;

	return true;
}

} // End of namespace Liath
