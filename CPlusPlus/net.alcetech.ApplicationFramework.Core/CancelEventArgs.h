/*
 * CancelEventArgs.h
 *
 *  Created on: Apr 20, 2016
 *      Author: beckermj
 */

#ifndef CANCELEVENTARGS_H_
#define CANCELEVENTARGS_H_

#include "EventArgs.h"

namespace ApplicationFramework {

class CancelEventArgs : public EventArgs {
private:
	bool _canceled;
public:
	CancelEventArgs();
	virtual ~CancelEventArgs();

	bool isCanceled();
	void cancel();
};

} /* namespace ApplicationFramework */

#endif /* CANCELEVENTARGS_H_ */
