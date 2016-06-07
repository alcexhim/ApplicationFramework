/*
 * MainWindow.h
 *
 *  Created on: Apr 7, 2016
 *      Author: beckermj
 */

#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QtCore/QtCore>
#include <QtGui/QtGui>
#include <QtWidgets/QtWidgets>

#include <Application.h>
#include <CancelEventArgs.h>
#include <Collections/Generic/Dictionary.h>
#include <Collections/Generic/List.h>
#include <CommandItem.h>
#include <CommandReferenceCommandItem.h>
#include <ModifierKeys.h>
#include <SeparatorCommandItem.h>
#include <Dimension2D.h>

#include <String.h>
#include <Text/StringBuilder.h>

#include "CommandBar.h"
#include "DocumentTab.h"
#include "GuiApplication.h"
#include "Panel.h"
#include "PanelArea.h"
#include "PanelAreaLocation.h"
#include "PanelBase.h"
#include "PanelGroup.h"
#include "PanelReference.h"
#include "Perspective.h"

#include "Internal/QFXMainWindow.h"

using ApplicationFramework::CancelEventArgs;
using ApplicationFramework::Collections::Generic::Dictionary;
using ApplicationFramework::Collections::Generic::List;
using ApplicationFramework::CommandItem;
using ApplicationFramework::Dimension2D;
using ApplicationFramework::ModifierKeys;
using ApplicationFramework::String;
using ApplicationFramework::Text::StringBuilder;

using ApplicationFramework::UserInterface::Internal::QFXMainWindow;

namespace ApplicationFramework {
namespace UserInterface {

class MainWindow : public QObject {

	Q_OBJECT

private:
	void create();
	QFXMainWindow* _handle;
	Dimension2D* _minimumSize;
	Dictionary<QAction*, Command*>* _actionCommands;

	Perspective* _perspective;

	void initCommandItem(CommandItem* item, QMenuBar* menuBar, QMenu* parentMenu);
	bool eventFilter(QObject *obj, QEvent *event);

	QTabWidget* _documentTabs;
	bool _fullScreen;
	bool _maximized;

	QMenu* _tabContextMenu;
	QDockWidget* loadQDockWidgetForPanel(Panel* panel);

	List<QToolBar*>* _perspectiveToolBars;
	List<QDockWidget*>* _perspectiveDockWidgets;
	List<QAction*>* _perspectiveMenuItems;

	static QWidget* createMenuItemForCommand(QMenuBar* menuBar, Command* cmd, QMenu* parentMenu);

private slots:
	void actionTriggered(bool checked);
	void tabIndexChanged(int index);
	void tabCloseRequested(int index);
	void tabContextMenuRequested(const QPoint &pos);
	void _handle_closing(CancelEventArgs* e);

public:
	MainWindow();
	virtual ~MainWindow();

	QFXMainWindow* getHandle();

	bool isCreated();

	bool isVisible();
	void setVisible(bool value);

	String* getTitle();
	void setTitle(String* value);

	Dimension2D* getMinimumSize();
	void setMinimumSize(Dimension2D* value);

	Perspective* getPerspective();
	void setPerspective(Perspective* persp);

	bool getFullScreen();
	void setFullScreen(bool value);
	void toggleFullScreen();

	void addDocumentTab(const char* shortName, const char* longName, QWidget* widget);
	void addDocumentTab(String* shortName, String* longName, QWidget* widget);

	DocumentTab* getCurrentDocumentTab();
	DocumentTab* getDocumentTabAt(int index);
	List<DocumentTab*>* getDocumentTabsList();

	bool close();

	void closeAllDocuments();
};

} /* namespace UserInterface */
} /* namespace ApplicationFramework */

#endif /* MAINWINDOW_H_ */
