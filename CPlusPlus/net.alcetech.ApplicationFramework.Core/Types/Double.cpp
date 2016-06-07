/*
 * Double.cpp
 *
 *  Created on: May 8, 2016
 *      Author: beckermj
 */

#include "Double.h"

namespace ApplicationFramework {
namespace Types {

Double::Double(double value) {
	this->_Value = value;
}

Double::~Double() {
	// TODO Auto-generated destructor stub
}

Double* Double::parse(const char* value) {
	double retval = 0.0;
	sscanf(value, "%lf", &retval);
	return new Double(retval);
}
Double* Double::parse(String* value) {
	return Double::parse(value->toCharArray());
}

} /* namespace Types */
} /* namespace ApplicationFramework */
