/*
 * BidirectionalDictionary.cpp
 *
 *  Created on: Apr 2, 2016
 *      Author: beckermj
 */

#include "BidirectionalDictionary.h"

namespace ApplicationFramework {
namespace Collections {
namespace Generic {

template<typename T1, typename T2> BidirectionalDictionary<T1, T2>::BidirectionalDictionary() {
	this->_forwardDictionary = new Dictionary<T1, T2>();
	this->_backwardDictionary = new Dictionary<T2, T1>();
}

template<typename T1, typename T2> BidirectionalDictionary<T1, T2>::~BidirectionalDictionary() {
	// TODO Auto-generated destructor stub
}

template<typename T1, typename T2> void BidirectionalDictionary<T1, T2>::add(T1 value1, T2 value2) {
	this->_forwardDictionary->add(value1, value2);
	this->_backwardDictionary->add(value2, value1);
}
template<typename T1, typename T2> void BidirectionalDictionary<T1, T2>::removeByValue1(T1 value1) {
	T2* value2 = this->_forwardDictionary->get(value1);
	this->_forwardDictionary->remove(value1);
	this->_backwardDictionary->remove(value2);
}
template<typename T1, typename T2> void BidirectionalDictionary<T1, T2>::removeByValue2(T2 value2) {
	T1* value1 = this->_backwardDictionary->get(value2);
	this->_forwardDictionary->remove(value1);
	this->_backwardDictionary->remove(value2);
}

template<typename T1, typename T2> void BidirectionalDictionary<T1, T2>::getValue1(T2 value2) {
	T1* value1 = this->_backwardDictionary->get(value2);
	return value1;
}
template<typename T1, typename T2> void BidirectionalDictionary<T1, T2>::getValue2(T1 value1) {
	T2* value2 = this->_forwardDictionary->get(value1);
	return value2;
}

template<typename T1, typename T2> int BidirectionalDictionary<T1, T2>::count() {
		if (_forwardDictionary->count() != _backwardDictionary->count())
		{
			// this should never happen
			// throw new InvalidOperationException("Count mismatch");
			return 0;
		}

		// they should be equal, so choose one at random to return and hardcode it ;)
		return _backwardDictionary->count();
}

} /* namespace Generic */
} /* namespace Collections */
} /* namespace ApplicationFramework */
