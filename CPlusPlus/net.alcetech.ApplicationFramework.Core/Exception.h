/*
 * Exception.h
 *
 *  Created on: Apr 17, 2016
 *      Author: beckermj
 */

#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include "Property.h"
#include "String.h"

namespace ApplicationFramework {

class Exception {
	AFX_PROPERTY(String*, Message);
	AFX_PROPERTY(Exception*, InnerException);

public:
	Exception();
	virtual ~Exception();

	Exception(String* message);
	Exception(String* message, Exception* innerException);
};

} /* namespace ApplicationFramework */

#endif /* EXCEPTION_H_ */
