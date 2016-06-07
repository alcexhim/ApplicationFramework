/*
 * Property.h
 *
 *  Created on: Apr 12, 2016
 *      Author: beckermj
 */

#ifndef PROPERTY_H_
#define PROPERTY_H_

#define AFX_PROPERTY(datatype, name) \
	private: \
		datatype _##name; \
	public: \
		datatype get##name() { return this->_##name; } \
		void set##name(datatype value) { this->_##name = value; }

#define AFX_PROPERTY_READONLY(datatype, name) \
	private: \
		datatype _##name; \
	public: \
		datatype get##name() { return this->_##name; }

#define AFX_PROPERTY_BOOL(name) \
	private: \
		bool _##name; \
	public: \
		bool is##name() { return this->_##name; } \
		void set##name(bool value) { this->_##name = value; }

#define AFX_PROPERTY_BOOL_READONLY(name) \
	private: \
		bool _##name; \
	public: \
		bool is##name() { return this->_##name; }

#endif /* PROPERTY_H_ */
