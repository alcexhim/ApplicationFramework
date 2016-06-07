/*
 * Object.cpp
 *
 *  Created on: Apr 8, 2016
 *      Author: beckermj
 */

#include "Object.h"

namespace ApplicationFramework {

Object::Object() {
	// TODO Auto-generated constructor stub

}

Object::~Object() {
	// TODO Auto-generated destructor stub
}

bool Object::equals(Object* compareWith) {
	return this->compareTo(compareWith) == 0;
}
int Object::compareTo(Object* compareWith) {
	if (this == compareWith) return 0;
	return -1;
}

bool Object::operator==(Object* right) {
	return (this->equals(right));
}
bool Object::operator!=(Object* right) {
	return (!this->equals(right));
}
bool Object::operator>(Object* right) {
	return this->compareTo(right) > 0;
}
bool Object::operator<(Object* right) {
	return this->compareTo(right) < 0;
}

} /* namespace ApplicationFramework */
