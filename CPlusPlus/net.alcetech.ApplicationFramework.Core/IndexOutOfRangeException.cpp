/*
 * IndexOutOfRangeException.cpp
 *
 *  Created on: Apr 18, 2016
 *      Author: beckermj
 */

#include "IndexOutOfRangeException.h"

namespace ApplicationFramework {

IndexOutOfRangeException::IndexOutOfRangeException() {
	// TODO Auto-generated constructor stub

}

IndexOutOfRangeException::~IndexOutOfRangeException() {
	// TODO Auto-generated destructor stub
}

IndexOutOfRangeException::IndexOutOfRangeException(String* argument, String* minimum, String* maximum) {
	this->setArgument(argument);
	this->setMinimum(minimum);
	this->setMaximum(maximum);
}

} /* namespace ApplicationFramework */
