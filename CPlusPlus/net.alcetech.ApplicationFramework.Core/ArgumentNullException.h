/*
 * ArgumentNullException.h
 *
 *  Created on: Apr 17, 2016
 *      Author: beckermj
 */

#ifndef ARGUMENTNULLEXCEPTION_H_
#define ARGUMENTNULLEXCEPTION_H_

#include "ArgumentException.h"
#include "Text/StringBuilder.h"

using ApplicationFramework::Text::StringBuilder;

namespace ApplicationFramework {

class ArgumentNullException : public ArgumentException {
public:
	ArgumentNullException();
	virtual ~ArgumentNullException();

	ArgumentNullException(String* argumentName);
	ArgumentNullException(String* message, Exception* innerException) : ArgumentException(message, innerException) { }
};

} /* namespace ApplicationFramework */

#endif /* ARGUMENTNULLEXCEPTION_H_ */
