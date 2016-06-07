/*
 * List.h
 *
 *  Created on: Apr 1, 2016
 *      Author: beckermj
 */

#ifndef LIST_H_
#define LIST_H_

#include "../../Object.h"

using ApplicationFramework::Object;

namespace ApplicationFramework {
namespace Collections {
namespace Generic {

template <typename T> class List {
private:
	T* _items;
	int _capacity;
	int _count;
public:
	List();
	virtual ~List();

	List(int capacity);

	void add(T item);
	int count();
	bool remove(T item);
	bool contains(T item);
	bool isEmpty();

	T get(int index);
	void set(int index, T value);

	void clear();

	T* toArray();
};

} /* namespace Generic */
} /* namespace Collections */
} /* namespace ApplicationFramework */

#include "List.tpp"

#endif /* LIST_H_ */
