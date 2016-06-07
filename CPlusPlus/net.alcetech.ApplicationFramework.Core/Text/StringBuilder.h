/*
 * StringBuilder.h
 *
 *  Created on: Apr 2, 2016
 *      Author: beckermj
 */

#ifndef STRINGBUILDER_H_
#define STRINGBUILDER_H_

#include <malloc.h>
#include <string.h>

#include "../String.h"

#include "../Collections/Generic/List.h"
#include "../Types/Char.h"

using ApplicationFramework::Collections::Generic::List;
using ApplicationFramework::String;
using ApplicationFramework::Types::Char;

namespace ApplicationFramework {
namespace Text {

class StringBuilder {
private:
	char* _buffer;
	int _capacity;
public:
	StringBuilder();
	virtual ~StringBuilder();

	StringBuilder(int capacity);
	StringBuilder(String* value);
	StringBuilder(const char* value);

	/**
	 * Appends the specified string to the end of this StringBuilder.
	 */
	void append(String* value);
	/**
	 * Appends the specified character to the end of this StringBuilder.
	 */
	void append(char value);
	/**
	 * Appends the specified string to the end of this StringBuilder.
	 */
	void append(const char* value);
	/**
	 * Appends the value of the specified StringBuilder to the end of this StringBuilder.
	 */
	void append(StringBuilder* value);

	void set(String* value);

	/**
	 * Removes all whitespace characters from the beginning and end of this StringBuilder.
	 */
	void trim();
	void trimStart();
	void trimEnd();

	/**
	 * Removes all specified characters from the beginning and end of this StringBuilder.
	 */
	void trim(List<Char*>* trimChars);
	void trimStart(List<Char*>* trimChars);
	void trimEnd(List<Char*>* trimChars);

	void replace(char findWhat, char replaceWith);
	void replace(String* findWhat, String* replaceWith);

	StringBuilder* copy();

	/**
	 * Returns the value of this StringBuilder as a C++ string (String*).
	 */
	String* toString();

	List<String*>* split(char delimiter);
	List<String*>* split(const char* delimiter);
	List<String*>* split(String* delimiter);

	int indexOf(char value);
	int indexOf(String* value);

	int lastIndexOf(char value);
	int lastIndexOf(String* value);

	bool contains(String* value);

	/**
	 * Determines whether the current string begins with the specified value.
	 */
	bool startsWith(String* value);
	/**
	 * Determines whether the current string begins with the specified value.
	 */
	bool startsWith(const char* value);
	/**
	 * Determines whether the current string ends with the specified value.
	 */
	bool endsWith(String* value);
	/**
	 * Determines whether the current string ends with the specified value.
	 */
	bool endsWith(const char* value);

	/**
	 * Determines whether the current string equals the specified value.
	 */
	bool equals(String* value);

	String* substring(int start);
	String* substring(int start, int length);

	int getLength();

	void clear();

	/**
	 * Returns true if this string matches the empty string (""); false otherwise.
	 */
	bool isEmpty();
};

} /* namespace Text */
} /* namespace ApplicationFramework */

#endif /* STRINGBUILDER_H_ */
