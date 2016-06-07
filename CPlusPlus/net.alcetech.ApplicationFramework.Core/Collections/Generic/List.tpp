/*
 * List.cpp
 *
 *  Created on: Apr 1, 2016
 *      Author: beckermj
 */

#include "List.h"

#include <malloc.h>

namespace ApplicationFramework {
namespace Collections {
namespace Generic {

template<typename T> List<T>::List() {
	this->_capacity = 10;
	this->_count = 0;
	this->_items = (T*)malloc(sizeof(T) * 10);
}
template<typename T> List<T>::List(int capacity) {
	this->_capacity = capacity;
	this->_count = 0;
	this->_items = (T*)malloc(sizeof(T) * capacity);
}

template<typename T> List<T>::~List() {
	free(this->_items);
}

template<typename T> void List<T>::add(T item) {
	if (this->_count >= this->_capacity)
	{
		this->_capacity *= 2;
		this->_items = (T*) realloc(this->_items, sizeof(T) * this->_capacity);
	}
	this->_count++;
	this->_items[this->_count - 1] = item;
}

template<typename T> bool List<T>::remove(T item) {
	int removed = 0;
	int j = 0;
	T* newarray = (T*)malloc(sizeof(T) * this->_capacity);

	// IMPORTANT:	do not check if the List<T> contains the item with List<T>::contains
	//				because a loop is already in use for going through and removing the item

	for (int i = 0; i < this->_count; i++)
	{
		if (this->_items[i] == item)
		{
			removed++;
		}
		else
		{
			newarray[j] = this->_items[i];
			j++;
		}
	}
	this->_items = newarray;

	if (removed > 0)
	{
		this->_count -= removed;
		return true;
	}
	return false;
}

template<typename T> bool List<T>::contains(T item) {
	for (int i = 0; i < this->_count; i++)
	{
		Object* first = (Object*)item;
		Object* second = (Object*)this->_items[i];
		
		if (first != NULL && second != NULL) {
			if (first->equals(second)) return true;
		}
		else {
			if (this->_items[i] == item) return true;
		}
	}
	return false;
}

template<typename T> int List<T>::count() {
	return this->_count;
}

template<typename T> bool List<T>::isEmpty() {
	return this->_count <= 0;
}

template<typename T> T List<T>::get(int index) {
	if (index < 0 || index >= this->_count)
	{
		printf("appfx: List<T>: get(): index %d out of range (0 - %d)", index, this->_count);
		return NULL;
	}
	return this->_items[index];
}
template<typename T> void List<T>::set(int index, T value) {
	if (index < 0 || index >= this->_count)
	{
		printf("appfx: List<T>: set(): index %d out of range (0 - %d)", index, this->_count);
		return;
	}
	this->_items[index] = value;
}

template<typename T> void List<T>::clear() {
	T* newarray = (T*)malloc(sizeof(T) * this->_capacity);
	this->_count = 0;
	this->_items = newarray;
}
	
template<typename T> T* List<T>::toArray() {
	T* array = (T*)malloc(sizeof(T) * this->_count);
	for (int i = 0; i < this->_count; i++)
	{
		array[i] = this->get(i);
	}
	return array;
}

} /* namespace Generic */
} /* namespace Collections */
} /* namespace ApplicationFramework */
