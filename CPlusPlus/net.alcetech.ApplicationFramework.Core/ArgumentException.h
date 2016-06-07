/*
 * ArgumentException.h
 *
 *  Created on: Apr 17, 2016
 *      Author: beckermj
 */

#ifndef ARGUMENTEXCEPTION_H_
#define ARGUMENTEXCEPTION_H_

#include "Exception.h"

namespace ApplicationFramework {

class ArgumentException : public Exception {

	AFX_PROPERTY(String*, Value);

public:
	ArgumentException();
	virtual ~ArgumentException();

	ArgumentException(String* message, Exception* innerException) : Exception(message, innerException) { }
	ArgumentException(String* message, String* value);
};

} /* namespace ApplicationFramework */

#endif /* ARGUMENTEXCEPTION_H_ */
