/*
 * Console.h
 *
 *  Created on: Apr 2, 2016
 *      Author: beckermj
 */

#ifndef CONSOLE_H_
#define CONSOLE_H_

#include <stdio.h>
#include <stdarg.h>

namespace ApplicationFramework {

class Console {
private:
	Console();
public:
	virtual ~Console();

	static void write(const char* value, ...);
	static void writeLine(const char* value, ...);
	static void writeLine();
};

} /* namespace ApplicationFramework */

#endif /* CONSOLE_H_ */
