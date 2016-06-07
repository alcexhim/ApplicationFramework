/*
 * Dimension2D.h
 *
 *  Created on: Apr 7, 2016
 *      Author: beckermj
 */

#ifndef DIMENSION2D_H_
#define DIMENSION2D_H_

namespace ApplicationFramework {

class Dimension2D {
private:
	double _width;
	double _height;
public:
	Dimension2D(double width, double height);
	virtual ~Dimension2D();

	double getWidth();
	void setWidth(double value);

	double getHeight();
	void setHeight(double value);
};

} /* namespace ApplicationFramework */

#endif /* DIMENSION2D_H_ */
