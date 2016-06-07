/*
 * PanelReference.cpp
 *
 *  Created on: Apr 19, 2016
 *      Author: beckermj
 */

#include "PanelReference.h"

namespace ApplicationFramework {
namespace UserInterface {

PanelReference::PanelReference() {
	this->_PanelID = String::EMPTY;
}
PanelReference::PanelReference(String* panelID) {
	this->_PanelID = panelID;
}

PanelReference::~PanelReference() {
	// TODO Auto-generated destructor stub
}

} /* namespace UserInterface */
} /* namespace ApplicationFramework */
