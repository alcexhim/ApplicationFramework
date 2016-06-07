/*
 * DocumentTab.cpp
 *
 *  Created on: Apr 14, 2016
 *      Author: beckermj
 */

#include "DocumentTab.h"

namespace ApplicationFramework {
namespace UserInterface {

DocumentTab::DocumentTab(QTabWidget* parentWidget, int index) {
	this->_parentWidget = parentWidget;
	this->_index = index;
}

DocumentTab::~DocumentTab() {
	// TODO Auto-generated destructor stub
}

void DocumentTab::close() {
	this->_parentWidget->removeTab(this->_index);
}

} /* namespace UserInterface */
} /* namespace ApplicationFramework */
