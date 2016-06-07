/*
 * ArgumentNullException.cpp
 *
 *  Created on: Apr 17, 2016
 *      Author: beckermj
 */

#include "ArgumentNullException.h"

namespace ApplicationFramework {

ArgumentNullException::ArgumentNullException() {
	// TODO Auto-generated constructor stub

}

ArgumentNullException::~ArgumentNullException() {
	// TODO Auto-generated destructor stub
}

ArgumentNullException::ArgumentNullException(String* argumentName) {
	StringBuilder* sb = new StringBuilder();
	sb->append("The argument '");
	sb->append(argumentName);
	sb->append("' cannot be null");

	this->setMessage(sb->toString());
}

} /* namespace ApplicationFramework */
