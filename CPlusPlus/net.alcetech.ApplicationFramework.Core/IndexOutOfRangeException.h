/*
 * IndexOutOfRangeException.h
 *
 *  Created on: Apr 18, 2016
 *      Author: beckermj
 */

#ifndef INDEXOUTOFRANGEEXCEPTION_H_
#define INDEXOUTOFRANGEEXCEPTION_H_

#include "Exception.h"
#include "Property.h"
#include "String.h"

namespace ApplicationFramework {

class IndexOutOfRangeException: public Exception {

	AFX_PROPERTY(String*, Argument);
	AFX_PROPERTY(String*, Minimum);
	AFX_PROPERTY(String*, Maximum);

public:
	IndexOutOfRangeException();
	virtual ~IndexOutOfRangeException();

	IndexOutOfRangeException(String* argument, String* minimum, String* maximum);
};

} /* namespace ApplicationFramework */

#endif /* INDEXOUTOFRANGEEXCEPTION_H_ */
