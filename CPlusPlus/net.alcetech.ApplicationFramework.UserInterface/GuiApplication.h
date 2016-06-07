/*
 * WindowManager.h
 *
 *  Created on: Apr 9, 2016
 *      Author: beckermj
 */

#ifndef GUIAPPLICATION_H_
#define GUIAPPLICATION_H_

#include "MainWindow.h"
#include "Panel.h"
#include "Perspective.h"

#include "Internal/QFXMainWindow.h"

using ApplicationFramework::UserInterface::Internal::QFXMainWindow;

namespace ApplicationFramework {
namespace UserInterface {

class MainWindow;

class GuiApplication {
private:
	static MainWindow* _currentMainWindow;
	static List<Panel*>* _panels;
	static List<Perspective*>* _perspectives;
	static Perspective* _defaultPerspective;
public:
	static void initialize(int argc, char** argv);

	static MainWindow* getCurrentMainWindow();
	static void setCurrentMainWindow(MainWindow* value);

	static MainWindow* getMainWindowForQMainWindow(QFXMainWindow* mainWindow);
	static void setMainWindowForQMainWindow(QFXMainWindow* key, MainWindow* vaiue);

	static Dictionary<QFXMainWindow*, MainWindow*>* _mainWindowsForQMainWindow;

	static void addPanel(Panel* item);
	static List<Panel*>* getPanelsList();

	static void addPerspective(Perspective* item);
	static Perspective* getPerspective(String* id);
	static Perspective* getPerspective(const char* id);
	static List<Perspective*>* getPerspectivesList();

	static Perspective* getDefaultPerspective();
	static void setDefaultPerspective(Perspective* value);

	static Panel* getPanel(String* id);
	static Panel* getPanel(const char* id);

	static void start();
};

} /* namespace UserInterface */
} /* namespace ApplicationFramework */

#endif /* GUIAPPLICATION_H_ */
