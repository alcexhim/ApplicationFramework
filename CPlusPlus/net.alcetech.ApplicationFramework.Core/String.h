/*
 * String.h
 *
 *  Created on: Apr 8, 2016
 *      Author: beckermj
 */

#ifndef STRING_H_
#define STRING_H_

#include "Object.h"
#include <string.h>
#include <stdio.h>

namespace ApplicationFramework {

class String : public Object {
private:
	const char* _value;
public:
	String(const char* value);
	virtual ~String();

	const char* getValue();
	void setValue(const char* value);

	virtual bool equals(Object* compareTo);
	bool equals(const char* value);

	bool matches(String* pattern);
	bool matches(const char* pattern);

	int length();

	char charAt(int index);

	static String* EMPTY;
	const char* toCharArray();

	String* operator=(const char* value);

	operator const char*();

	bool operator==(String* value);
	bool operator!=(String* value);
};

} /* namespace ApplicationFramework */

#endif /* STRING_H_ */
