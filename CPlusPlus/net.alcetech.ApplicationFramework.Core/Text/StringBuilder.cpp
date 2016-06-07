/*
 * StringBuilder.cpp
 *
 *  Created on: Apr 2, 2016
 *      Author: beckermj
 */

#include "StringBuilder.h"

#define STRINGBUILDER_INITIAL_CAPACITY 256

namespace ApplicationFramework {
namespace Text {

/**
 * Constructs a StringBuilder with the default initial capacity (256).
 */
StringBuilder::StringBuilder() {
	this->_capacity = STRINGBUILDER_INITIAL_CAPACITY;
	this->_buffer = (char*)malloc(sizeof(char) * (STRINGBUILDER_INITIAL_CAPACITY + 1));
	this->_buffer[0] = 0;
}
/**
 * Constructs a StringBuilder with the specified initial capacity.
 */
StringBuilder::StringBuilder(int capacity) {
	this->_capacity = capacity;
	this->_buffer = (char*)malloc(sizeof(char) * (this->_capacity + 1));
	this->_buffer[0] = 0;
}
StringBuilder::StringBuilder(const char* value) {
	int len = strlen(value);
	this->_capacity = len + 1;
	this->_buffer = (char*)malloc(sizeof(char) * this->_capacity);
	strcpy(this->_buffer, value);
	this->_buffer[len] = 0;
}
/**
 * Constructs a StringBuilder from the specified string.
 */
StringBuilder::StringBuilder(String* value) {
	int len = value->length();
	this->_capacity = len + 1;
	this->_buffer = (char*)malloc(sizeof(char) * this->_capacity);
	strcpy(this->_buffer, value->getValue());
	this->_buffer[len] = 0;
}

StringBuilder::~StringBuilder() {
	// TODO Auto-generated destructor stub
}

/**
 * Sets the value of this StringBuilder to the specified string.
 */
void StringBuilder::set(String* value) {
	this->clear();
	this->append(value);
}

void StringBuilder::trim() {
	this->trimStart();
	this->trimEnd();
}
void StringBuilder::trim(List<Char*>* trimChars) {
	this->trimStart(trimChars);
	this->trimEnd(trimChars);
}

void StringBuilder::trimStart() {
	List<Char*>* trimChars = Char::getWhitespaceCharsList();
	this->trimStart(trimChars);
}
void StringBuilder::trimStart(List<Char*>* trimChars) {

	StringBuilder* sb = new StringBuilder();
	int len = this->getLength();
	bool done = false;

	for (int i = 0; i < len; i++)
	{
		if (!trimChars->contains(new Char(this->_buffer[i])) || done)
		{
			sb->append(this->_buffer[i]);
		}
		else
		{
			done = true;
		}
	}
	strcpy(this->_buffer, sb->toString()->toCharArray());
}

void StringBuilder::trimEnd() {
	List<Char*>* trimChars = Char::getWhitespaceCharsList();
	this->trimEnd(trimChars);
}
void StringBuilder::trimEnd(List<Char*>* trimChars) {
	StringBuilder* sb = new StringBuilder();
	int len = strlen(this->_buffer);
	int startIndex = -1;
	for (int i = len - 1; i >= 0; i--)
	{
		if (trimChars->contains(new Char(this->_buffer[i])))
		{
			startIndex = i;
			break;
		}
	}
	if (startIndex > -1)
	{
		for (int i = 0; i < startIndex; i++)
		{
			sb->append(this->_buffer[i]);
		}
	}
	strcpy(this->_buffer, sb->toString()->toCharArray());
}

void StringBuilder::replace(char findWhat, char replaceWith)
{
	StringBuilder* newSB = new StringBuilder(this->_capacity);
	for (int i = 0; i < this->getLength(); i++)
	{
		if (this->_buffer[i] == findWhat)
		{
			newSB->append(replaceWith);
		}
		else
		{
			newSB->append(this->_buffer[i]);
		}
	}
	this->_buffer = newSB->_buffer;
}
void StringBuilder::replace(String* findWhat, String* replaceWith)
{
	printf("appfx: StringBuilder::replace(String*, String*) not implemented\n");
}

StringBuilder* StringBuilder::copy() {
	StringBuilder* sb = new StringBuilder();
	sb->append(this->toString());
	return sb;
}

void StringBuilder::append(String* value) {
	this->append(value->toCharArray());
}
void StringBuilder::append(char value) {
	int currentLen = strlen(this->_buffer);
	int targetLen = 1;

	while (currentLen + targetLen > this->_capacity)
	{
		this->_capacity *= 2;
	}

	this->_buffer = (char*)realloc(this->_buffer, sizeof(char) * (this->_capacity + 1));
	this->_buffer[currentLen] = value;
	this->_buffer[currentLen + 1] = 0;
}
void StringBuilder::append(const char* value) {
	int currentLen = strlen(this->_buffer);
	int targetLen = strlen(value);

	while (currentLen + targetLen > this->_capacity)
	{
		this->_capacity *= 2;
	}

	this->_buffer = (char*)realloc(this->_buffer, sizeof(char) * (this->_capacity + 1));
	strcat(this->_buffer, value);
}
void StringBuilder::append(StringBuilder* value) {
	this->append(value->toString());
}

String* StringBuilder::toString() {
	int len = strlen(this->_buffer);
	char* value = (char*)malloc(sizeof(char) * (len + 1));
	memset(value, 0, len + 1);
	memcpy(value, this->_buffer, len);
	String* retval = new String(value);
	return retval;
}

List<String*>* StringBuilder::split(char delimiter) {
	char* str = (char*)malloc(sizeof(char) * 2);
	str[0] = delimiter;
	str[1] = 0;
	return this->split(new String(str));
}
List<String*>* StringBuilder::split(String* delimiter) {
	return this->split(delimiter->toCharArray());
}
List<String*>* StringBuilder::split(const char* delimiter) {
	List<String*>* list = new List<String*>();
	char* val = strtok(this->_buffer, delimiter);
	while (val != NULL)
	{
		list->add(new String(val));
		val = strtok(NULL, delimiter);
	}
	return list;
}

void StringBuilder::clear() {
	free(this->_buffer);

	this->_buffer = (char*)malloc(sizeof(char) * (this->_capacity + 1));
	this->_buffer[0] = 0;
}

bool StringBuilder::isEmpty() {
	return (strcmp(this->_buffer, "") == 0);
}

bool StringBuilder::contains(String* value) {
	return (this->indexOf(value) != -1);
}
int StringBuilder::indexOf(char value) {
	char* str = (char*)malloc(sizeof(char) * 2);
	str[0] = value;
	str[1] = 0;
	return this->indexOf(new String(str));
}
int StringBuilder::indexOf(String* value) {
	int len = strlen(this->_buffer);
	int vallen = value->length();

	for (int i = 0; i < len - vallen; i++)
	{
		String* substr = this->substring(i, vallen);
		if (substr->equals(value)) return i;
	}
	return -1;
}

int StringBuilder::lastIndexOf(char value) {
	char* str = (char*)malloc(sizeof(char) * 2);
	str[0] = value;
	str[1] = 0;
	return this->lastIndexOf(new String(str));
}
int StringBuilder::lastIndexOf(String* value) {
	int len = strlen(this->_buffer);
	int vallen = value->length();

	for (int i = len - vallen - 1; i >= 0; i--)
	{
		String* substr = this->substring(i, vallen);
		if (substr->equals(value)) return i;
	}
	return -1;
}

bool StringBuilder::startsWith(const char* value) {
	return this->startsWith(new String(value));
}
bool StringBuilder::endsWith(const char* value) {
	return this->endsWith(new String(value));
}
bool StringBuilder::startsWith(String* value) {
	int len = value->length();
	String* compareWith = this->substring(0, len);
	return value->equals(compareWith);
}
bool StringBuilder::endsWith(String* value) {
	int len = value->length();
	String* compareWith = this->substring(this->getLength() - len, len);
	return value->equals(compareWith);
}

bool StringBuilder::equals(String* value) {
	return (strcmp(this->_buffer, value->toCharArray()) == 0);
}

String* StringBuilder::substring(int start) {
	return this->substring(start, this->getLength() - start);
}
String* StringBuilder::substring(int start, int length) {
	if ((start + length) > this->getLength())
	{
		printf("appfx: StringBuilder::substring() - invalid start %d and end %d for string length %d\n", start, length, this->getLength());
		return this->substring(start, this->getLength() - start);
	}

	char* value = (char*)malloc(sizeof(char) * (length + 1));
	memcpy(value, this->_buffer + start, length);
	value[length] = 0;
	return new String(value);
}

int StringBuilder::getLength() {
	return strlen(this->_buffer);
}

} /* namespace Text */
} /* namespace ApplicationFramework */
