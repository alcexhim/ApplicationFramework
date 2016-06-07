/*
 * Dictionary.cpp
 *
 *  Created on: Apr 2, 2016
 *      Author: beckermj
 */

#ifndef COLLECTIONS_GENERIC_DICTIONARY_TPP_
#define COLLECTIONS_GENERIC_DICTIONARY_TPP_

#include "Dictionary.h"

namespace ApplicationFramework {
namespace Collections {
namespace Generic {

template<typename T1, typename T2> Dictionary<T1, T2>::Dictionary() {
	this->_keys = new List<T1>();
	this->_values = new List<T2>();
}

template<typename T1, typename T2> Dictionary<T1, T2>::~Dictionary() {
	// TODO Auto-generated destructor stub
}

template<typename T1, typename T2> void Dictionary<T1, T2>::add(T1 key, T2 value) {
	this->_keys->add(key);
	this->_values->add(value);
}
template<typename T1, typename T2> void Dictionary<T1, T2>::set(T1 key, T2 value) {
	bool found = false;
	for (int i = 0; i < this->_keys->count(); i++)
	{
		if (this->_keys->get(i) == key)
		{
			this->_values->set(i, value);
			found = true;
			break;
		}
	}
	if (!found) this->add(key, value);
}

template<typename T1, typename T2> T2 Dictionary<T1, T2>::get(T1 key) {
	for (int i = 0; i < this->_keys->count(); i++)
	{
		Object* keyObject1 = dynamic_cast<Object*>(key);
		Object* keyObject2 = dynamic_cast<Object*>(this->_keys->get(i));
		if (keyObject1 != NULL && keyObject2 != NULL) {
			if (keyObject1->equals(keyObject2)) return this->_values->get(i);
		}
		else {
			if (this->_keys->get(i) == key) return this->_values->get(i);
		}
	}
	return NULL;
}

template<typename T1, typename T2> bool Dictionary<T1, T2>::containsKey(T1 key) {
	return this->_keys->contains(key);
}
template<typename T1, typename T2> bool Dictionary<T1, T2>::containsValue(T2 value) {
	return this->_values->contains(value);
}

} /* namespace Generic */
} /* namespace Collections */
} /* namespace ApplicationFramework */

#endif // COLLECTIONS_GENERIC_DICTIONARY_TPP_