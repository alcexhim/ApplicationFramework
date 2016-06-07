/*
 * Stack.h
 *
 *  Created on: Apr 1, 2016
 *      Author: beckermj
 */

#ifndef STACK_H_
#define STACK_H_

#include "List.h"

namespace ApplicationFramework {
namespace Collections {
namespace Generic {

template <typename T> class Stack
{
private:
	List<T> _list;
public:
	Stack();
	virtual ~Stack();

	void push(T item);
	T pop();
};

} /* namespace Generic */
} /* namespace Collections */
} /* namespace ApplicationFramework */

#endif /* STACK_H_ */
