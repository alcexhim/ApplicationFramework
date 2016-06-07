/*
 * Panel.h
 *
 *  Created on: Apr 9, 2016
 *      Author: beckermj
 */

#ifndef PANEL_H_
#define PANEL_H_

#include <String.h>
#include <QtCore/QtCore>
#include <QtGui/QtGui>
#include <QtWidgets/QtWidgets>

#include "PanelBase.h"

#include <Property.h>

namespace ApplicationFramework {
namespace UserInterface {

/**
 * A dockable container for a widget.
 */
class Panel {

	AFX_PROPERTY(String*, ID);
	AFX_PROPERTY(String*, Title);
	AFX_PROPERTY(QWidget*, Widget);

public:
	Panel();
	virtual ~Panel();

	// each time a new Window is created, it loads the Panels and since Widgets are only created once per Panel
	// only the most recently instantiated QDockWidget gets the associated panel widget.
	// we get around this by instead of creating Widgets once and then Panel->setWidget() we associate an
	// initialization function to the panel which gets called each time a new Panel is instantiated and creates
	// a brand-new Widget every time
	void(*_initializationFunction)(Panel*);
};

} /* namespace UserInterface */
} /* namespace ApplicationFramework */

#endif /* PANEL_H_ */
