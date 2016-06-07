/*
 * Char.cpp
 *
 *  Created on: May 8, 2016
 *      Author: beckermj
 */

#include "Char.h"

namespace ApplicationFramework {
namespace Types {

List<Char*>* Char::_whitespaceCharsList = new List<Char*>();

Char::Char(char value) {
	this->_value = value;
}

Char::~Char() {
	// TODO Auto-generated destructor stub
}

char Char::getValue() {
	return this->_value;
}

int Char::compareTo(Object* value) {
	Char* charr = dynamic_cast<Char*>(value);
	if (charr != NULL) {
		return this->getValue() - charr->getValue();
	}
	return -1;
}

List<Char*>* Char::getWhitespaceCharsList() {
	if (Char::_whitespaceCharsList == NULL)
	{
		List<Char*>* list = new List<Char*>();
		list->add(new Char(' '));
		list->add(new Char('\t'));
		list->add(new Char('\n'));
		list->add(new Char('\r'));
		Char::_whitespaceCharsList = list;
	}
	return Char::_whitespaceCharsList;
}

} /* namespace Types */
} /* namespace ApplicationFramework */
