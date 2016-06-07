/*
 * Command.cpp
 *
 *  Created on: Apr 6, 2016
 *      Author: beckermj
 */

#include "Command.h"

namespace ApplicationFramework {

Command::Command() {
	this->_ID = String::EMPTY;
	this->_title = String::EMPTY;
	this->_commandItems = new List<CommandItem*>();
	this->_shortcut = NULL;
	this->_extraData = new Dictionary<String*, Object*>();
}

Command::~Command() {
	// TODO Auto-generated destructor stub
}

String* Command::getID() {
	return this->_ID;
}
void Command::setID(String* value) {
	this->_ID = value;
}

String* Command::getTitle() {
	return this->_title;
}
void Command::setTitle(String * value) {
	this->_title = value;
}

void Command::addCommandItem(CommandItem* item) {
	this->_commandItems->add(item);
}

List<CommandItem*>* Command::getCommandItemsList() {
	return this->_commandItems;
}

Shortcut* Command::getShortcut() {
	return this->_shortcut;
}
void Command::setShortcut(Shortcut* value) {
	this->_shortcut = value;
}

Object* Command::getExtraData(const char* key) {
	return this->getExtraData(new String(key));
}
Object* Command::getExtraData(String* key) {
	return this->_extraData->get(key);
}
void Command::setExtraData(const char* key, Object* value) {
	return this->setExtraData(new String(key), value);
}
void Command::setExtraData(String* key, Object* value) {
	this->_extraData->set(key, value);
}

} /* namespace ApplicationFramework */
