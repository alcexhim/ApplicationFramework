/*
 * Perspective.cpp
 *
 *  Created on: Apr 10, 2016
 *      Author: beckermj
 */

#include "Perspective.h"

namespace ApplicationFramework {
namespace UserInterface {

Perspective::Perspective() {
	this->_ID = String::EMPTY;
	this->_Title = String::EMPTY;

	this->_PanelAreasList = new List<PanelArea*>();
	this->_CommandBarsList = new List<CommandBar*>();
}

Perspective::~Perspective() {
	// TODO Auto-generated destructor stub
}

void Perspective::addPanelArea(PanelArea* item) {
	this->getPanelAreasList()->add(item);
}
void Perspective::addCommandBar(CommandBar* item) {
	this->getCommandBarsList()->add(item);
}

} /* namespace UserInterface */
} /* namespace ApplicationFramework */
