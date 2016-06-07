/*
 * PanelGroup.cpp
 *
 *  Created on: Apr 12, 2016
 *      Author: beckermj
 */

#include "PanelGroup.h"

namespace ApplicationFramework {
namespace UserInterface {

PanelGroup::PanelGroup() {
	this->_panelsList = new List<PanelBase*>();
}

PanelGroup::~PanelGroup() {
	// TODO Auto-generated destructor stub
}

void PanelGroup::addPanel(PanelBase* item) {
	this->_panelsList->add(item);
}
List<PanelBase*>* PanelGroup::getPanelsList() {
	return this->_panelsList;
}

} /* namespace UserInterface */
} /* namespace ApplicationFramework */
