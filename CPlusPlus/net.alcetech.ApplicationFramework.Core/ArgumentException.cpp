/*
 * ArgumentException.cpp
 *
 *  Created on: Apr 17, 2016
 *      Author: beckermj
 */

#include "ArgumentException.h"

namespace ApplicationFramework {

ArgumentException::ArgumentException() {
	// TODO Auto-generated constructor stub

}

ArgumentException::~ArgumentException() {
	// TODO Auto-generated destructor stub
}

ArgumentException::ArgumentException(String* message, String* value) {
	this->setMessage(message);
	this->setValue(value);
}

} /* namespace ApplicationFramework */
