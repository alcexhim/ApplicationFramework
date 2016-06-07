/*
 * MainWindow.cpp
 *
 *  Created on: Apr 7, 2016
 *      Author: beckermj
 */

#include "MainWindow.h"

using Qt::DockWidgetArea;

namespace ApplicationFramework {
namespace UserInterface {

MainWindow::MainWindow() {
	this->_handle = NULL;
	this->_minimumSize = NULL;
	this->_actionCommands = new Dictionary<QAction*, Command*>();
	this->_documentTabs = NULL;
	this->_fullScreen = false;
	this->_maximized = false;
	this->_perspective = NULL;

	this->_perspectiveToolBars = new List<QToolBar*>();
	this->_perspectiveDockWidgets = new List<QDockWidget*>();
	this->_perspectiveMenuItems = new List<QAction*>();

	this->_tabContextMenu = new QMenu();
	this->setTitle(Application::getTitle());
}

MainWindow::~MainWindow() {
	// TODO Auto-generated destructor stub
}

QFXMainWindow* MainWindow::getHandle() {
	return this->_handle;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
	QFXMainWindow* qmw = dynamic_cast<QFXMainWindow*>(obj);
	if (qmw != NULL)
	{
		if (event->type() == QEvent::WindowActivate) {
			MainWindow* mw = GuiApplication::getMainWindowForQMainWindow(qmw);
			GuiApplication::setCurrentMainWindow(mw);
		}
	}
	return false;
}

void MainWindow::initCommandItem(CommandItem* item, QMenuBar* menuBar, QMenu* parentMenu)
{
	SeparatorCommandItem* sep = dynamic_cast<SeparatorCommandItem*>(item);
	if (sep != NULL)
	{
		if (parentMenu == NULL)
		{
			menuBar->addSeparator();
		}
		else
		{
			parentMenu->addSeparator();
		}
		return;
	}

	CommandReferenceCommandItem* crci = dynamic_cast<CommandReferenceCommandItem*>(item);
	if (crci != NULL)
	{
		Command* cmd = Application::getCommand(crci->getCommandID());
		if (cmd != NULL)
		{
			StringBuilder* sbTitle = new StringBuilder(cmd->getTitle());
			sbTitle->replace('_', '&');
			String* cmdtitle = sbTitle->toString();

			List<CommandItem*>* items = cmd->getCommandItemsList();
			if (items->count() == 0)
			{
				QAction* action = NULL;
				if (parentMenu == NULL)
				{
					action = menuBar->addAction(QString(cmdtitle->toCharArray()));
				}
				else
				{
					action = parentMenu->addAction(QString(cmdtitle->toCharArray()));
				}

				if (cmd->getShortcut() != NULL)
				{
					StringBuilder* sbKeySequence = new StringBuilder();
					if ((cmd->getShortcut()->getModifierKeys() & ModifierKeys::Control) == ModifierKeys::Control)
					{
						sbKeySequence->append("Ctrl+");
					}
					if (cmd->getShortcut()->getModifierKeys() & ModifierKeys::Shift)
					{
						sbKeySequence->append("Shift+");
					}
					if (cmd->getShortcut()->getModifierKeys() & ModifierKeys::Alt)
					{
						sbKeySequence->append("Alt+");
					}
					if (cmd->getShortcut()->getModifierKeys() & ModifierKeys::Super)
					{
						sbKeySequence->append("Win+");
					}
					sbKeySequence->append(cmd->getShortcut()->getKeyString());

					action->setShortcut(QKeySequence(sbKeySequence->toString()->toCharArray()));
					action->setShortcutContext(Qt::ShortcutContext::WindowShortcut);
				}

				this->_actionCommands->add(action, cmd);

				connect(action, SIGNAL(triggered(bool)), this, SLOT(actionTriggered(bool)));
			}
			else
			{
				QMenu* menu = NULL;
				if (parentMenu == NULL)
				{
					menu = menuBar->addMenu(QString(cmdtitle->toCharArray()));
				}
				else
				{
					menu = parentMenu->addMenu(QString(cmdtitle->toCharArray()));
				}
				menu->setTearOffEnabled(true);

				for (int i = 0; i < items->count(); i++)
				{
					CommandItem* item1 = items->get(i);
					this->initCommandItem(item1, menuBar, menu);
				}
			}
		}
		return;
	}
}

QDockWidget* MainWindow::loadQDockWidgetForPanel(Panel* panel) {
	QDockWidget* qdw = new QDockWidget();
	qdw->setWindowTitle(panel->getTitle()->toCharArray());
	if (panel->_initializationFunction != NULL)
	{
		panel->_initializationFunction(panel);
	}
	if (panel->getWidget() != NULL)
	{
		qdw->setWidget(panel->getWidget());
	}
	return qdw;
}

void MainWindow::actionTriggered(bool checked) {
	QObject* sender = QObject::sender();
	QAction* action = dynamic_cast<QAction*>(sender);
	if (action != NULL)
	{
		Command* cmd = this->_actionCommands->get(action);
		if (cmd != NULL)
		{
			bool result = Application::executeCommand(cmd);
			if (!result)
			{
				printf("appfx: executeCommand - command '%s' undefined\n", cmd->getID()->toCharArray());
			}
		}
	}
}

void MainWindow::tabIndexChanged(int index) {
	printf("set current document index %d\n", index);
}
void MainWindow::tabCloseRequested(int index) {

	this->getDocumentTabAt(index)->close();
}
void MainWindow::tabContextMenuRequested(const QPoint &pos) {
	this->_tabContextMenu->move(pos);
	this->_tabContextMenu->show();
}

void MainWindow::create() {
	if (this->isCreated()) return;

	QFXMainWindow* mainWindow = new QFXMainWindow();
	this->_handle = mainWindow;

	GuiApplication::setMainWindowForQMainWindow(mainWindow, this);

	this->_handle->setDockNestingEnabled(true);
	this->_handle->installEventFilter(this);
	// connect(this->_handle, SIGNAL(triggered(bool)), this, SLOT(actionTriggered(bool)));
	connect(this->_handle, SIGNAL(closing(CancelEventArgs*)), this, SLOT(_handle_closing(CancelEventArgs*)));

	if (this->getMinimumSize() != NULL)
	{
		int width = this->getMinimumSize()->getWidth();
		int height = this->getMinimumSize()->getHeight();
		mainWindow->setMinimumSize(width, height);
	}
	mainWindow->setVisible(this->isVisible());
	mainWindow->statusBar()->setVisible(true);

	List<CommandItem*>* commandItemsList = Application::getMainMenuCommandItemsList();
	for (int i = 0; i < commandItemsList->count(); i++)
	{
		CommandItem* item = commandItemsList->get(i);
		this->initCommandItem(item, mainWindow->menuBar(), NULL);
	}


	QAction* actionContextMenuClose = this->_tabContextMenu->addAction("Close");
	Command* cmdClose = new Command();
	cmdClose->setID(new String("DocumentContextMenuClose"));
	this->_actionCommands->add(actionContextMenuClose, cmdClose);
	connect(actionContextMenuClose, SIGNAL(triggered(bool)), this, SLOT(actionTriggered(bool)));

	QAction* actionContextMenuCloseAllButThis = this->_tabContextMenu->addAction("Close All but This");
	Command* cmdCloseAllButThis = new Command();
	cmdCloseAllButThis->setID(new String("DocumentContextMenuCloseAllButThis"));
	this->_actionCommands->add(actionContextMenuCloseAllButThis, cmdCloseAllButThis);
	connect(actionContextMenuCloseAllButThis, SIGNAL(triggered(bool)), this, SLOT(actionTriggered(bool)));

	this->_documentTabs = new QTabWidget();
	this->_documentTabs->setDocumentMode(true);
	this->_documentTabs->setTabsClosable(true);
	connect(this->_documentTabs, SIGNAL(currentChanged(int)), this, SLOT(tabIndexChanged(int)));
	connect(this->_documentTabs, SIGNAL(tabCloseRequested(int)), this, SLOT(tabCloseRequested(int)));
	connect(this->_documentTabs, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(tabContextMenuRequested(const QPoint &)));

	this->_handle->setCentralWidget(this->_documentTabs);
	this->setPerspective(NULL);
}

void MainWindow::setPerspective(Perspective* persp) {
	if (persp == NULL) persp = GuiApplication::getDefaultPerspective();
	this->_perspective = persp;

	// remove the toolbars from the previous perspective
	for (int i = 0; i < this->_perspectiveToolBars->count(); i++) {
		this->_handle->removeToolBar(this->_perspectiveToolBars->get(i));
	}
	this->_perspectiveToolBars->clear();

	// remove the dock widgets from the previous perspective
	for (int i = 0; i < this->_perspectiveDockWidgets->count(); i++) {
		this->_handle->removeDockWidget(this->_perspectiveDockWidgets->get(i));
	}
	this->_perspectiveDockWidgets->clear();

	for (int i = 0; i < this->_perspectiveMenuItems->count(); i++) {
		this->_handle->menuBar()->removeAction(this->_perspectiveMenuItems->get(i));
	}
	this->_perspectiveMenuItems->clear();

	List<CommandBar*>* commandBarsList = persp->getCommandBarsList();
	for (int i = 0; i < commandBarsList->count(); i++)
	{
		CommandBar* cb = commandBarsList->get(i);

		QToolBar* tb = new QToolBar();
		tb->setWindowTitle(cb->getTitle()->toCharArray());

		List<CommandItem*>* listCommandBarItems = cb->getItemsList();
		for (int j = 0; j < listCommandBarItems->count(); j++)
		{
			CommandItem* item = listCommandBarItems->get(j);

			CommandReferenceCommandItem* crci = dynamic_cast<CommandReferenceCommandItem*>(item);
			if (crci != NULL)
			{
				Command* cmd = Application::getCommand(crci->getCommandID());

				StringBuilder* sbTitle = new StringBuilder(cmd->getTitle());
				sbTitle->replace('_', '&');
				String* cmdtitle = sbTitle->toString();

				List<CommandItem*>* listCommandItems = cmd->getCommandItemsList();
				if (listCommandItems->count() > 0)
				{
					QAction* action = tb->addAction(cmdtitle->toCharArray());
					connect(action, SIGNAL(triggered(bool)), this, SLOT(actionTriggered(bool)));
					this->_actionCommands->add(action, cmd);
				}
				else
				{
					QAction* action = tb->addAction(cmdtitle->toCharArray());
					connect(action, SIGNAL(triggered(bool)), this, SLOT(actionTriggered(bool)));
					this->_actionCommands->add(action, cmd);
				}
			}

			SeparatorCommandItem* sep = dynamic_cast<SeparatorCommandItem*>(item);
			if (sep != NULL)
			{
				tb->addSeparator();
			}
		}

		this->_handle->addToolBar(tb);
		this->_perspectiveToolBars->add(tb);
	}

	List<PanelArea*>* panelAreasList = persp->getPanelAreasList();
	for (int i = 0; i < panelAreasList->count(); i++)
	{
		PanelArea* pa = panelAreasList->get(i);

		List<PanelBase*>* panelsList = pa->getPanelsList();
		for (int j = 0; j < panelsList->count(); j++)
		{
			PanelBase* panelBase = panelsList->get(j);

			PanelGroup* panelGroup = dynamic_cast<PanelGroup*>(panelBase);
			if (panelGroup != NULL)
			{
				List<PanelBase*>* panelGroupItemsList = panelGroup->getPanelsList();
				QDockWidget* prevQdw = NULL;
				for (int k = 0; k < panelGroupItemsList->count(); k++)
				{
					PanelBase* panelBase1 = panelGroupItemsList->get(k);
					PanelReference* panelRef = dynamic_cast<PanelReference*>(panelBase1);

					if (panelRef != NULL)
					{
						QDockWidget* qdw = this->loadQDockWidgetForPanel(GuiApplication::getPanel(panelRef->getPanelID()));
						if (prevQdw == NULL)
						{
							switch (pa->getLocation())
							{
								case PanelAreaLocation::None:
								{
									break;
								}
								case PanelAreaLocation::Left:
								{
									this->_handle->addDockWidget(DockWidgetArea::LeftDockWidgetArea, qdw);
									break;
								}
								case PanelAreaLocation::Top:
								{
									this->_handle->addDockWidget(DockWidgetArea::TopDockWidgetArea, qdw);
									break;
								}
								case PanelAreaLocation::Bottom:
								{
									this->_handle->addDockWidget(DockWidgetArea::BottomDockWidgetArea, qdw);
									break;
								}
								case PanelAreaLocation::Right:
								{
									this->_handle->addDockWidget(DockWidgetArea::RightDockWidgetArea, qdw);
									break;
								}
							}
							prevQdw = qdw;
						}
						else
						{
							this->_handle->tabifyDockWidget(prevQdw, qdw);
						}

						this->_perspectiveDockWidgets->add(qdw);
					}
				}
			}

			PanelReference* panel = dynamic_cast<PanelReference*>(panelBase);
			if (panel != NULL)
			{
				QDockWidget* qdw = this->loadQDockWidgetForPanel(GuiApplication::getPanel(panel->getPanelID()));
				switch (pa->getLocation())
				{
					case PanelAreaLocation::None:
					{
						break;
					}
					case PanelAreaLocation::Left:
					{
						this->_handle->addDockWidget(DockWidgetArea::LeftDockWidgetArea, qdw);
						break;
					}
					case PanelAreaLocation::Top:
					{
						this->_handle->addDockWidget(DockWidgetArea::TopDockWidgetArea, qdw);
						break;
					}
					case PanelAreaLocation::Bottom:
					{
						this->_handle->addDockWidget(DockWidgetArea::BottomDockWidgetArea, qdw);
						break;
					}
					case PanelAreaLocation::Right:
					{
						this->_handle->addDockWidget(DockWidgetArea::RightDockWidgetArea, qdw);
						break;
					}
				}
				this->_perspectiveDockWidgets->add(qdw);
			}
		}
	}

	/*
	List<CommandItem*>* mainMenuCommandItemsForPerspective = persp->getMainMenuCommandItemsList();
	for (int i = 0; i < mainMenuCommandItemsForPerspective->count(); i++) {
		CommandItem* item = mainMenuCommandItemsForPerspective->get(i);
		QAction* qa = MainWindow::createQActionForCommandItem
		_perspectiveMenuItems->add(qa);
	}
	*/
}

bool MainWindow::isCreated() {
	return (this->_handle != NULL);
}

bool MainWindow::isVisible() {
	this->create();
	return this->_handle->isVisible();
}
void MainWindow::setVisible(bool value) {
	this->create();
	this->_handle->setVisible(value);
}

String* MainWindow::getTitle() {
	this->create();

	return String::EMPTY;
	// return new String(this->_handle->windowTitle());
}
void MainWindow::setTitle(String* value) {
	this->create();
	this->_handle->setWindowTitle(value->toCharArray());
}

Dimension2D* MainWindow::getMinimumSize() {
	return this->_minimumSize;
}
void MainWindow::setMinimumSize(Dimension2D* value) {
	this->create();
	this->_minimumSize = value;
	if (this->_minimumSize != NULL)
	{
		this->_handle->setMinimumSize(this->_minimumSize->getWidth(), this->_minimumSize->getHeight());
	}
	else
	{
		// TODO: figure out how to unset minimum size after set
	}
}

bool MainWindow::getFullScreen() {
	return this->_fullScreen;
}
void MainWindow::setFullScreen(bool value) {
	if (value)
	{
		this->_maximized = this->_handle->isMaximized();
		this->_handle->showFullScreen();
		this->_fullScreen = true;
	}
	else
	{
		if (this->_maximized)
		{
			this->_handle->showMaximized();
		}
		else
		{
			this->_handle->showNormal();
		}
		this->_fullScreen = false;
	}
}
void MainWindow::toggleFullScreen() {
	this->setFullScreen(!this->getFullScreen());
}

void MainWindow::addDocumentTab(const char* shortName, const char* longName, QWidget* widget) {
	this->_documentTabs->addTab(widget, shortName);
	this->_documentTabs->setTabToolTip(this->_documentTabs->indexOf(widget), longName);
}
void MainWindow::addDocumentTab(String* shortName, String* longName, QWidget* widget) {
	this->addDocumentTab(shortName->toCharArray(), longName->toCharArray(), widget);
}

DocumentTab* MainWindow::getCurrentDocumentTab() {
	int index = this->_documentTabs->currentIndex();
	if (index < 0) return NULL;

	return new DocumentTab(this->_documentTabs, index);
}
DocumentTab* MainWindow::getDocumentTabAt(int index) {
	return new DocumentTab(this->_documentTabs, index);
}

List<DocumentTab*>* MainWindow::getDocumentTabsList() {
	List<DocumentTab*>* list = new List<DocumentTab*>();
	for (int i = 0; i < this->_documentTabs->count(); i++)
	{
		DocumentTab* dt = new DocumentTab(this->_documentTabs, i);
		list->add(dt);
	}
	return list;
}

bool MainWindow::close() {
	return this->_handle->close();
}

void MainWindow::closeAllDocuments() {
	while (this->getDocumentTabsList()->count() > 0)
	{
		this->getDocumentTabsList()->get(0)->close();
	}
}

void MainWindow::_handle_closing(CancelEventArgs* e) {

	List<DocumentTab*>* list = this->getDocumentTabsList();
	if (list->count() > 0)
	{
		for (int i = 0; i < list->count(); i++)
		{

		}
		e->cancel();
	}
}

} /* namespace UserInterface */
} /* namespace ApplicationFramework */

#include "MainWindow.moc"
