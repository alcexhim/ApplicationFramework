/*
 * Int32.cpp
 *
 *  Created on: May 5, 2016
 *      Author: beckermj
 */

#include "Int32.h"

namespace ApplicationFramework {
namespace Types {

Int32::Int32(int value) {
	this->_Value = value;
}

Int32::~Int32() {
	// TODO Auto-generated destructor stub
}

int Int32::getValue() {
	return this->_Value;
}

int Int32::compareTo(Object* compareWith) {
	Int32* val = dynamic_cast<Int32*>(compareWith);
	if (val == NULL) return -1;

	return this->getValue() - val->getValue();
}

} /* namespace Types */
} /* namespace ApplicationFramework */
