/*
 * QFXMainWindow.h
 *
 *  Created on: Apr 20, 2016
 *      Author: beckermj
 */

#ifndef INTERNAL_QFXMAINWINDOW_H_
#define INTERNAL_QFXMAINWINDOW_H_

#include <QtCore/QtCore>
#include <QtGui/QtGui>
#include <QtWidgets/QtWidgets>

#include <CancelEventArgs.h>

using ApplicationFramework::CancelEventArgs;

namespace ApplicationFramework {
namespace UserInterface {
namespace Internal {

class QFXMainWindow : public QMainWindow {

	Q_OBJECT

protected:
	void closeEvent(QCloseEvent* event) Q_DECL_OVERRIDE;

public:
	QFXMainWindow();
	virtual ~QFXMainWindow();

signals:
	void closing(CancelEventArgs* e);

};

} /* namespace Internal */
} /* namespace UserInterface */
} /* namespace ApplicationFramework */

#endif /* INTERNAL_QFXMAINWINDOW_H_ */
