/*
 * CommandReferenceCommandItem.cpp
 *
 *  Created on: Apr 2, 2016
 *      Author: beckermj
 */

#include "CommandReferenceCommandItem.h"

namespace ApplicationFramework {

CommandReferenceCommandItem::CommandReferenceCommandItem() {
	this->_commandID = String::EMPTY;
}
CommandReferenceCommandItem::CommandReferenceCommandItem(const char* commandID) {
	this->_commandID = new String(commandID);
}
CommandReferenceCommandItem::CommandReferenceCommandItem(String* commandID) {
	this->_commandID = commandID;
}

CommandReferenceCommandItem::~CommandReferenceCommandItem() {
	// TODO Auto-generated destructor stub
}

void CommandReferenceCommandItem::setCommandID(String* value) {
	this->_commandID = value;
}
String* CommandReferenceCommandItem::getCommandID() {
	return this->_commandID;
}

} /* namespace ApplicationFramework */
