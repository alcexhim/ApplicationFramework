/*
 * DocumentTab.h
 *
 *  Created on: Apr 14, 2016
 *      Author: beckermj
 */

#ifndef DOCUMENTTAB_H_
#define DOCUMENTTAB_H_

#include <QtCore/QtCore>
#include <QtGui/QtGui>
#include <QtWidgets/QtWidgets>

namespace ApplicationFramework {
namespace UserInterface {

class DocumentTab {
private:
	QTabWidget* _parentWidget;
	int _index;

public:
	DocumentTab(QTabWidget* parentWidget, int index);
	virtual ~DocumentTab();

	void close();
};

} /* namespace UserInterface */
} /* namespace ApplicationFramework */

#endif /* DOCUMENTTAB_H_ */
