/*
 * Console.cpp
 *
 *  Created on: Apr 2, 2016
 *      Author: beckermj
 */

#include "Console.h"

namespace ApplicationFramework {

Console::Console() {
	// TODO Auto-generated constructor stub

}

Console::~Console() {
	// TODO Auto-generated destructor stub
}

void Console::write(const char* value, ...) {
	va_list		argptr;
	static char string[2][32000]; // in case va is called by nested functions
	static int	index = 0;
	char		*buf;

	buf = string[index & 1];
	index++;

	va_start(argptr, value);
	vsnprintf(buf, sizeof(*string), value, argptr);
	va_end(argptr);

	printf(buf);
}
void Console::writeLine(const char* value, ...) {

	va_list		argptr;
	static char string[2][32000]; // in case va is called by nested functions
	static int	index = 0;
	char		*buf;

	buf = string[index & 1];
	index++;

	va_start(argptr, value);
	vsnprintf(buf, sizeof(*string), value, argptr);
	va_end(argptr);

	printf(buf);
	printf("\n");
}
void Console::writeLine() {
	printf("\n");
}

} /* namespace ApplicationFramework */
