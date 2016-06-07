/*
 * SeparatorCommandItem.h
 *
 *  Created on: Apr 7, 2016
 *      Author: beckermj
 */

#ifndef SEPARATORCOMMANDITEM_H_
#define SEPARATORCOMMANDITEM_H_

#include "CommandItem.h"

namespace ApplicationFramework {

class SeparatorCommandItem : public CommandItem {
public:
	SeparatorCommandItem();
	virtual ~SeparatorCommandItem();
};

} /* namespace ApplicationFramework */

#endif /* SEPARATORCOMMANDITEM_H_ */
