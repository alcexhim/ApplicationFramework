/*
 * CommandBar.cpp
 *
 *  Created on: Apr 19, 2016
 *      Author: beckermj
 */

#include "CommandBar.h"

namespace ApplicationFramework {
namespace UserInterface {

CommandBar::CommandBar() {
	this->_ItemsList = new List<CommandItem*>();
	this->_Title = String::EMPTY;
}

CommandBar::~CommandBar() {
	// TODO Auto-generated destructor stub
}

void CommandBar::addItem(CommandItem* item) {
	this->getItemsList()->add(item);
}

} /* namespace UserInterface */
} /* namespace ApplicationFramework */
