/*
 * Double.h
 *
 *  Created on: May 8, 2016
 *      Author: beckermj
 */

#ifndef TYPES_DOUBLE_H_
#define TYPES_DOUBLE_H_

#include "../Property.h"
#include "../String.h"
#include <stdio.h>

namespace ApplicationFramework {
namespace Types {

class Double {

	AFX_PROPERTY_READONLY(double, Value);

public:
	Double(double value);
	virtual ~Double();

	static Double* parse(const char* value);
	static Double* parse(String* value);
};

} /* namespace Types */
} /* namespace ApplicationFramework */

#endif /* TYPES_DOUBLE_H_ */
