/*
 * PanelArea.cpp
 *
 *  Created on: Apr 12, 2016
 *      Author: beckermj
 */

#include "PanelArea.h"

namespace ApplicationFramework {
namespace UserInterface {

PanelArea::PanelArea() {
	this->_location = PanelAreaLocation::None;
	this->_panelsList = new List<PanelBase*>();
}

PanelArea::~PanelArea() {
	// TODO Auto-generated destructor stub
}

PanelAreaLocation PanelArea::getLocation() {
	return this->_location;
}
void PanelArea::setLocation(PanelAreaLocation value) {
	this->_location = value;
}

void PanelArea::addPanel(PanelBase* item) {
	this->_panelsList->add(item);
}
List<PanelBase*>* PanelArea::getPanelsList() {
	return this->_panelsList;
}

} /* namespace UserInterface */
} /* namespace ApplicationFramework */
