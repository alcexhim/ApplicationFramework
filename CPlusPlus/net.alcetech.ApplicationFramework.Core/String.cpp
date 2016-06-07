/*
 * String.cpp
 *
 *  Created on: Apr 8, 2016
 *      Author: beckermj
 */

#include "String.h"

namespace ApplicationFramework {

String::String(const char* value) {
	this->_value = value;
}

String::~String() {
	// TODO Auto-generated destructor stub
}

const char* String::getValue() {
	return this->_value;
}
void String::setValue(const char* value) {
	this->_value = value;
}

bool String::equals(Object* compareTo) {
	String* compareToString = dynamic_cast<String*>(compareTo);
	if (compareToString != NULL)
	{
		return (strcmp(this->getValue(), compareToString->getValue()) == 0);
	}
	return (this == compareTo);
}
bool String::equals(const char* value) {
	return (strcmp(this->getValue(), value) == 0);
}

char String::charAt(int index) {
	if (index < 0 || index >= this->length()) return 0;
	return this->_value[index];
}

bool String::matches(String* pattern) {
	return this->matches(pattern->toCharArray());
}
bool String::matches(const char* pattern) {
	int length = this->length();

	int patlen = strlen(pattern);
	int j = 0;
	bool matches = true;

	for (int i = 0; i < length; i++)
	{
		if (j >= patlen) {
			if (i < length)
			{
				// printf("pattern reached end before string\n");
				matches = false;
			}
			break;
		}

		if (pattern[j] == '*') {
			// match everything
			if (j + 1 < patlen) {
				if (pattern[j + 1] == this->charAt(i)) {
					j++;
					i--;
					continue;
				}
			}
		}
		else if (pattern[j] == '?') {
			// match any single character
			j++;
		}
		else {
			if (pattern[j] == this->charAt(i)) {
				j++;
				continue;
			}
			else {
				// printf("pattern[%d] '%c' does not equal this->charAt(%d) '%c'\n", j, pattern[j], i, this->charAt(i));
				matches = false;
				break;
			}
		}
	}
	return matches;
}

int String::length() {
	return strlen(this->_value);
}
const char* String::toCharArray() {
	return this->_value;
}

String* String::operator=(const char* value) {
	this->setValue(value);
	return this;
}

String::operator const char*() {
	return this->toCharArray();
}

bool String::operator==(String* value) {
	printf("in operator==\n");
	return this->equals(value);
}
bool String::operator!=(String* value) {
	return !this->equals(value);
}

String* String::EMPTY = new String("");

} /* namespace ApplicationFramework */
