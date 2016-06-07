/*
 * Panel.cpp
 *
 *  Created on: Apr 9, 2016
 *      Author: beckermj
 */

#include "Panel.h"

namespace ApplicationFramework {
namespace UserInterface {

Panel::Panel() {
	this->_ID = String::EMPTY;
	this->_Title = String::EMPTY;
	this->_Widget = NULL;
	this->_initializationFunction = NULL;
}

Panel::~Panel() {
	// TODO Auto-generated destructor stub
}

} /* namespace UserInterface */
} /* namespace ApplicationFramework */
