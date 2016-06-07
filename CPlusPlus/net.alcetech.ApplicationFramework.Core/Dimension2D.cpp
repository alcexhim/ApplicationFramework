/*
 * Dimension2D.cpp
 *
 *  Created on: Apr 7, 2016
 *      Author: beckermj
 */

#include "Dimension2D.h"

namespace ApplicationFramework {

Dimension2D::Dimension2D(double width, double height) {
	this->_width = width;
	this->_height = height;
}

Dimension2D::~Dimension2D() {
	// TODO Auto-generated destructor stub
}

double Dimension2D::getWidth() {
	return this->_width;
}
void Dimension2D::setWidth(double value) {
	this->_width = value;
}

double Dimension2D::getHeight() {
	return this->_height;
}
void Dimension2D::setHeight(double value) {
	this->_height = value;
}

} /* namespace ApplicationFramework */
