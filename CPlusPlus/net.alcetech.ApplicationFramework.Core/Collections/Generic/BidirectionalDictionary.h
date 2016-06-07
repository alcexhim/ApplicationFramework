/*
 * BidirectionalDictionary.h
 *
 *  Created on: Apr 2, 2016
 *      Author: beckermj
 */

#ifndef COLLECTIONS_GENERIC_BIDIRECTIONALDICTIONARY_H_
#define COLLECTIONS_GENERIC_BIDIRECTIONALDICTIONARY_H_

#include "Dictionary.h"

namespace ApplicationFramework {
namespace Collections {
namespace Generic {

template<typename T1, typename T2> class BidirectionalDictionary {
private:
	Dictionary<T1, T2>* _forwardDictionary;
	Dictionary<T2, T1>* _backwardDictionary;
public:
	BidirectionalDictionary();
	virtual ~BidirectionalDictionary();

	void add(T1 value1, T2 value2);

	void removeByValue1(T1 value1);
	void removeByValue2(T2 value2);

	void getValue1(T2 value2);
	void getValue2(T1 value1);

	int count();
};

} /* namespace Generic */
} /* namespace Collections */
} /* namespace ApplicationFramework */

#include "BidirectionalDictionary.tpp"

#endif /* COLLECTIONS_GENERIC_BIDIRECTIONALDICTIONARY_H_ */

