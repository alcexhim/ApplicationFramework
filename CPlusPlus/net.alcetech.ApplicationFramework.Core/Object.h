/*
 * Object.h
 *
 *  Created on: Apr 8, 2016
 *      Author: beckermj
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#ifndef NULL
#define NULL 0
#endif

namespace ApplicationFramework {

class Object {
public:
	Object();
	virtual ~Object();

	bool equals(Object* compareWith);
	virtual int compareTo(Object* compareWith);

	bool operator==(Object* right);
	bool operator!=(Object* right);
	bool operator>(Object* right);
	bool operator<(Object* right);
};

} /* namespace ApplicationFramework */

#endif /* OBJECT_H_ */
