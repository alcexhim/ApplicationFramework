/*
 * Int32.h
 *
 *  Created on: May 5, 2016
 *      Author: beckermj
 */

#ifndef TYPES_INT32_H_
#define TYPES_INT32_H_

#include <stdlib.h>
#include "../Object.h"

namespace ApplicationFramework {
namespace Types {

class Int32 : public Object {
private:
	int _Value;
public:
	Int32(int value);
	virtual ~Int32();

	virtual int compareTo(Object* compareWith);

	int getValue();
};

} /* namespace Types */
} /* namespace ApplicationFramework */

#endif /* TYPES_INT32_H_ */
