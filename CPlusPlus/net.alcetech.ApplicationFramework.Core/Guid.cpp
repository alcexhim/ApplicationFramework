/*
 * Guid.cpp
 *
 *  Created on: Apr 17, 2016
 *      Author: beckermj
 */

#include "Guid.h"

namespace ApplicationFramework {

Guid* Guid::EMPTY = new Guid();

Guid::Guid() {
	// TODO Auto-generated constructor stub

}

Guid::Guid(List<char>* list) {
    if (list == NULL)
        throw new ArgumentNullException(new String("list"));
    if (list->count() != 16)
        throw new ArgumentException(new String("Arg_GuidArrayCtor"), new String("16"));

	_a = ((int)list->get(3) << 24) | ((int)list->get(2) << 16) | ((int)list->get(1) << 8) | list->get(0);
	_b = (short)(((int)list->get(5) << 8) | list->get(4));
	_c = (short)(((int)list->get(7) << 8) | list->get(6));
	_d = list->get(8);
	_e = list->get(9);
	_f = list->get(10);
	_g = list->get(11);
	_h = list->get(12);
	_i = list->get(13);
	_j = list->get(14);
	_k = list->get(15);
}

Guid::~Guid() {
	// TODO Auto-generated destructor stub
}

Guid* Guid::fromString(String* value) {
	// TODO: implement this
	return Guid::EMPTY;
}

} /* namespace ApplicationFramework */
