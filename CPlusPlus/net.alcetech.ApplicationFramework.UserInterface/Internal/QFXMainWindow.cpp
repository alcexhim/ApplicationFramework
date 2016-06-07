/*
 * QFXMainWindow.cpp
 *
 *  Created on: Apr 20, 2016
 *      Author: beckermj
 */

#include "QFXMainWindow.h"

namespace ApplicationFramework {
namespace UserInterface {
namespace Internal {

QFXMainWindow::QFXMainWindow() {
	// TODO Auto-generated constructor stub
}

QFXMainWindow::~QFXMainWindow() {
	// TODO Auto-generated destructor stub
}

void QFXMainWindow::closeEvent(QCloseEvent* event) {
	CancelEventArgs* e = new CancelEventArgs();
	emit closing(e);
	if (e->isCanceled())
	{
		event->ignore();
	}
	else
	{
		event->accept();
	}
}

} /* namespace Internal */
} /* namespace UserInterface */
} /* namespace ApplicationFramework */

#include "QFXMainWindow.moc"
