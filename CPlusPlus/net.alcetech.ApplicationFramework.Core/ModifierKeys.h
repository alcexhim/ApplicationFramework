/*
 * ModifierKeys.cpp
 *
 *  Created on: Apr 8, 2016
 *      Author: beckermj
 */

#ifndef MODIFIERKEYS_H_
#define MODIFIERKEYS_H_

namespace ApplicationFramework {

	enum ModifierKeys
	{
		None = 0,
		Control = 1,
		Alt = 2,
		Shift = 4,
		Meta = 8,
		Super = 16,
		Hyper = 32,
		Top = 64
	};

}

#endif /* MODIFIERKEYS_H */
