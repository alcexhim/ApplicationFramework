/*
 * Char.h
 *
 *  Created on: May 8, 2016
 *      Author: beckermj
 */

#ifndef TYPES_CHAR_H_
#define TYPES_CHAR_H_

#include "../Object.h"
#include "../Collections/Generic/List.h"

using ApplicationFramework::Collections::Generic::List;

namespace ApplicationFramework {
namespace Types {

class Char : public Object {
private:
	char _value;
	static List<Char*>* _whitespaceCharsList;
public:
	Char(char value);
	virtual ~Char();

	virtual int compareTo(Object* value);

	char getValue();

	static List<Char*>* getWhitespaceCharsList();
};

} /* namespace Types */
} /* namespace ApplicationFramework */

#endif /* TYPES_CHAR_H_ */
