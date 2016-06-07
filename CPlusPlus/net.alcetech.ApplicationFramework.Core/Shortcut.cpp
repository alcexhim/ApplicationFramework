/*
 * Shortcut.cpp
 *
 *  Created on: Apr 8, 2016
 *      Author: beckermj
 */

#include "Shortcut.h"

namespace ApplicationFramework {

Shortcut::Shortcut() {
	this->_modifierKeys = ModifierKeys::None;
	this->_key = KeyboardKeys::None;
}

Shortcut::~Shortcut() {
	// TODO Auto-generated destructor stub
}

int Shortcut::getModifierKeys() {
	return this->_modifierKeys;
}
void Shortcut::setModifierKeys(int value) {
	printf("setting modifier keys %d\n", value);
	this->_modifierKeys = value;
}

KeyboardKeys Shortcut::getKey() {
	return this->_key;
}
void Shortcut::setKey(KeyboardKeys value) {
	this->_key = value;
}

String* Shortcut::getKeyString() {
	switch (this->_key)
	{
		case KeyboardKeys::A: return new String("A");
		case KeyboardKeys::B: return new String("B");
		case KeyboardKeys::C: return new String("C");
		case KeyboardKeys::D: return new String("D");
		case KeyboardKeys::E: return new String("E");
		case KeyboardKeys::F: return new String("F");
		case KeyboardKeys::G: return new String("G");
		case KeyboardKeys::H: return new String("H");
		case KeyboardKeys::I: return new String("I");
		case KeyboardKeys::J: return new String("J");
		case KeyboardKeys::K: return new String("K");
		case KeyboardKeys::L: return new String("L");
		case KeyboardKeys::M: return new String("M");
		case KeyboardKeys::N: return new String("N");
		case KeyboardKeys::O: return new String("O");
		case KeyboardKeys::P: return new String("P");
		case KeyboardKeys::Q: return new String("Q");
		case KeyboardKeys::R: return new String("R");
		case KeyboardKeys::S: return new String("S");
		case KeyboardKeys::T: return new String("T");
		case KeyboardKeys::U: return new String("U");
		case KeyboardKeys::V: return new String("V");
		case KeyboardKeys::W: return new String("W");
		case KeyboardKeys::X: return new String("X");
		case KeyboardKeys::Y: return new String("Y");
		case KeyboardKeys::Z: return new String("Z");

		case KeyboardKeys::Apostrophe: return new String("Apostrophe");
		case KeyboardKeys::BackSlash: return new String("BackSlash");
		case KeyboardKeys::Backspace: return new String("Backspace");
		case KeyboardKeys::BracketClose: return new String("BracketClose");
		case KeyboardKeys::BracketOpen: return new String("BracketOpen");
		case KeyboardKeys::Comma: return new String("Comma");
		case KeyboardKeys::Delete: return new String("Del");

		case KeyboardKeys::End: return new String("End");
		case KeyboardKeys::Enter: return new String("Enter");
		case KeyboardKeys::Escape: return new String("Escape");

		case KeyboardKeys::F1: return new String("F1");
		case KeyboardKeys::F2: return new String("F2");
		case KeyboardKeys::F3: return new String("F3");
		case KeyboardKeys::F4: return new String("F4");
		case KeyboardKeys::F5: return new String("F5");
		case KeyboardKeys::F6: return new String("F6");
		case KeyboardKeys::F7: return new String("F7");
		case KeyboardKeys::F8: return new String("F8");
		case KeyboardKeys::F9: return new String("F9");
		case KeyboardKeys::F10: return new String("F10");
		case KeyboardKeys::F11: return new String("F11");
		case KeyboardKeys::F12: return new String("F12");

		case KeyboardKeys::Return: return new String("Return");

		case KeyboardKeys::NumPad0: return new String("NumPad0");
		case KeyboardKeys::NumPad1: return new String("NumPad1");
		case KeyboardKeys::NumPad2: return new String("NumPad2");
		case KeyboardKeys::NumPad3: return new String("NumPad3");
		case KeyboardKeys::NumPad4: return new String("NumPad4");
		case KeyboardKeys::NumPad5: return new String("NumPad5");
		case KeyboardKeys::NumPad6: return new String("NumPad6");
		case KeyboardKeys::NumPad7: return new String("NumPad7");
		case KeyboardKeys::NumPad8: return new String("NumPad8");
		case KeyboardKeys::NumPad9: return new String("NumPad9");

		case KeyboardKeys::TopRow0: return new String("TopRow0");
		case KeyboardKeys::TopRow1: return new String("TopRow1");
		case KeyboardKeys::TopRow2: return new String("TopRow2");
		case KeyboardKeys::TopRow3: return new String("TopRow3");
		case KeyboardKeys::TopRow4: return new String("TopRow4");
		case KeyboardKeys::TopRow5: return new String("TopRow5");
		case KeyboardKeys::TopRow6: return new String("TopRow6");
		case KeyboardKeys::TopRow7: return new String("TopRow7");
		case KeyboardKeys::TopRow8: return new String("TopRow8");
		case KeyboardKeys::TopRow9: return new String("TopRow9");
	}
	return String::EMPTY;
}
void Shortcut::setKeyString(String* value) {
	if (value->equals("A")) this->_key = KeyboardKeys::A;
	else if (value->equals("B")) this->_key = KeyboardKeys::B;
	else if (value->equals("C")) this->_key = KeyboardKeys::C;
	else if (value->equals("D")) this->_key = KeyboardKeys::D;
	else if (value->equals("E")) this->_key = KeyboardKeys::E;
	else if (value->equals("F")) this->_key = KeyboardKeys::F;
	else if (value->equals("G")) this->_key = KeyboardKeys::G;
	else if (value->equals("H")) this->_key = KeyboardKeys::H;
	else if (value->equals("I")) this->_key = KeyboardKeys::I;
	else if (value->equals("J")) this->_key = KeyboardKeys::J;
	else if (value->equals("K")) this->_key = KeyboardKeys::K;
	else if (value->equals("L")) this->_key = KeyboardKeys::L;
	else if (value->equals("M")) this->_key = KeyboardKeys::M;
	else if (value->equals("N")) this->_key = KeyboardKeys::N;
	else if (value->equals("O")) this->_key = KeyboardKeys::O;
	else if (value->equals("P")) this->_key = KeyboardKeys::P;
	else if (value->equals("Q")) this->_key = KeyboardKeys::Q;
	else if (value->equals("R")) this->_key = KeyboardKeys::R;
	else if (value->equals("S")) this->_key = KeyboardKeys::S;
	else if (value->equals("T")) this->_key = KeyboardKeys::T;
	else if (value->equals("U")) this->_key = KeyboardKeys::U;
	else if (value->equals("V")) this->_key = KeyboardKeys::V;
	else if (value->equals("W")) this->_key = KeyboardKeys::W;
	else if (value->equals("X")) this->_key = KeyboardKeys::X;
	else if (value->equals("Y")) this->_key = KeyboardKeys::Y;
	else if (value->equals("Z")) this->_key = KeyboardKeys::Z;

	else if (value->equals("Apostrophe")) this->_key = KeyboardKeys::Apostrophe;
	else if (value->equals("BackSlash")) this->_key = KeyboardKeys::BackSlash;
	else if (value->equals("Backslash")) this->_key = KeyboardKeys::BackSlash;
	else if (value->equals("Backspace")) this->_key = KeyboardKeys::Backspace;
	else if (value->equals("BracketClose")) this->_key = KeyboardKeys::BracketClose;
	else if (value->equals("BracketOpen")) this->_key = KeyboardKeys::BracketOpen;

	else if (value->equals("Del")) this->_key = KeyboardKeys::Delete;
	else if (value->equals("Delete")) this->_key = KeyboardKeys::Delete;

	else if (value->equals("NumPad0")) this->_key = KeyboardKeys::NumPad0;
	else if (value->equals("NumPad1")) this->_key = KeyboardKeys::NumPad1;
	else if (value->equals("NumPad2")) this->_key = KeyboardKeys::NumPad2;
	else if (value->equals("NumPad3")) this->_key = KeyboardKeys::NumPad3;
	else if (value->equals("NumPad4")) this->_key = KeyboardKeys::NumPad4;
	else if (value->equals("NumPad5")) this->_key = KeyboardKeys::NumPad5;
	else if (value->equals("NumPad6")) this->_key = KeyboardKeys::NumPad6;
	else if (value->equals("NumPad7")) this->_key = KeyboardKeys::NumPad7;
	else if (value->equals("NumPad8")) this->_key = KeyboardKeys::NumPad8;
	else if (value->equals("NumPad9")) this->_key = KeyboardKeys::NumPad9;

	else if (value->equals("TopRow0")) this->_key = KeyboardKeys::TopRow0;
	else if (value->equals("TopRow1")) this->_key = KeyboardKeys::TopRow1;
	else if (value->equals("TopRow2")) this->_key = KeyboardKeys::TopRow2;
	else if (value->equals("TopRow3")) this->_key = KeyboardKeys::TopRow3;
	else if (value->equals("TopRow4")) this->_key = KeyboardKeys::TopRow4;
	else if (value->equals("TopRow5")) this->_key = KeyboardKeys::TopRow5;
	else if (value->equals("TopRow6")) this->_key = KeyboardKeys::TopRow6;
	else if (value->equals("TopRow7")) this->_key = KeyboardKeys::TopRow7;
	else if (value->equals("TopRow8")) this->_key = KeyboardKeys::TopRow8;
	else if (value->equals("TopRow9")) this->_key = KeyboardKeys::TopRow9;
}

String* Shortcut::getModifierKeysString() {
	return String::EMPTY;
}
void Shortcut::setModifierKeysString(String* value) {
	StringBuilder* sb = new StringBuilder(value);
	List<String*>* list = sb->split(new String(","));
	int retval = ModifierKeys::None;
	for (int i = 0; i < list->count(); i++)
	{
		if (list->get(i)->equals("Control"))
		{
			printf("list has ModifierKeys::Control\n");
			retval |= ModifierKeys::Control;
		}
		if (list->get(i)->equals("Alt") || list->get(i)->equals("Meta"))
		{
			printf("list has ModifierKeys::Alt or ModifierKeys::Meta\n");
			retval |= ModifierKeys::Alt;
		}
		if (list->get(i)->equals("Shift"))
		{
			printf("list has ModifierKeys::Shift\n");
			retval |= ModifierKeys::Shift;
		}
		if (list->get(i)->equals("Win") || list->get(i)->equals("Super"))
		{
			printf("list has ModifierKeys::Win or ModifierKeys::Super\n");
			retval |= ModifierKeys::Super;
		}
	}
	this->setModifierKeys(retval);
}

} /* namespace ApplicationFramework */
