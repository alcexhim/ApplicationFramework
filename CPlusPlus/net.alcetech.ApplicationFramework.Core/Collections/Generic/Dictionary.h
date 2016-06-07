/*
 * Dictionary.h
 *
 *  Created on: Apr 2, 2016
 *      Author: beckermj
 */

#ifndef COLLECTIONS_GENERIC_DICTIONARY_H_
#define COLLECTIONS_GENERIC_DICTIONARY_H_

#include "List.h"
#include "../../Object.h"

namespace ApplicationFramework {
namespace Collections {
namespace Generic {

template<typename T1, typename T2> class Dictionary {
private:
	List<T1>* _keys;
	List<T2>* _values;
public:
	Dictionary();
	virtual ~Dictionary();

	void add(T1 key, T2 value);
	T2 get(T1 key);
	void set(T1 key, T2 value);

	bool containsKey(T1 key);
	bool containsValue(T2 value);
};

} /* namespace Generic */
} /* namespace Collections */
} /* namespace ApplicationFramework */

#include "Dictionary.tpp"

#endif /* COLLECTIONS_GENERIC_DICTIONARY_H_ */
