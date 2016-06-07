/*
 * Guid.h
 *
 *  Created on: Apr 17, 2016
 *      Author: beckermj
 */

#ifndef GUID_H_
#define GUID_H_

#include "ArgumentNullException.h"
#include "String.h"

#include "Collections/Generic/List.h"

using ApplicationFramework::Collections::Generic::List;

namespace ApplicationFramework {

class Guid {
private:
	Guid();

	int _a;
	short _b;
	short _c;
	char _d;
	char _e;
	char _f;
	char _g;
	char _h;
	char _i;
	char _j;
	char _k;
public:
	Guid(List<char>* list);
	virtual ~Guid();

	static Guid* EMPTY;

	static Guid* fromString(String* value);
};

} /* namespace ApplicationFramework */

#endif /* GUID_H_ */
