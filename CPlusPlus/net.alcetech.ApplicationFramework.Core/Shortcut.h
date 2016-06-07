/*
 * Shortcut.h
 *
 *  Created on: Apr 8, 2016
 *      Author: beckermj
 */

#ifndef SHORTCUT_H_
#define SHORTCUT_H_

#include "ModifierKeys.h"
#include "KeyboardKeys.h"
#include "Text/StringBuilder.h"

#include <string.h>

using ApplicationFramework::Text::StringBuilder;

namespace ApplicationFramework {

class Shortcut {
private:
	int _modifierKeys;
	KeyboardKeys _key;
public:
	Shortcut();
	virtual ~Shortcut();

	int getModifierKeys();
	void setModifierKeys(int value);

	KeyboardKeys getKey();
	void setKey(KeyboardKeys value);

	String* getKeyString();
	void setKeyString(String* value);

	String* getModifierKeysString();
	void setModifierKeysString(String* value);
};

} /* namespace ApplicationFramework */

#endif /* SHORTCUT_H_ */
