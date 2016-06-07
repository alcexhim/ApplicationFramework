/*
 * CancelEventArgs.cpp
 *
 *  Created on: Apr 20, 2016
 *      Author: beckermj
 */

#include "CancelEventArgs.h"

namespace ApplicationFramework {

CancelEventArgs::CancelEventArgs() {
	this->_canceled = false;
}

CancelEventArgs::~CancelEventArgs() {
	// TODO Auto-generated destructor stub
}

bool CancelEventArgs::isCanceled() {
	return this->_canceled;
}
void CancelEventArgs::cancel() {
	this->_canceled = true;
}

} /* namespace ApplicationFramework */
