/*
 * GuiApplication.cpp
 *
 *  Created on: Apr 9, 2016
 *      Author: beckermj
 */

#include "GuiApplication.h"

namespace ApplicationFramework {
namespace UserInterface {

MainWindow* GuiApplication::_currentMainWindow;
List<Panel*>* GuiApplication::_panels = new List<Panel*>();
Dictionary<QFXMainWindow*, MainWindow*>* GuiApplication::_mainWindowsForQMainWindow = new Dictionary<QFXMainWindow*, MainWindow*>();
List<Perspective*>* GuiApplication::_perspectives = new List<Perspective*>();
Perspective* GuiApplication::_defaultPerspective = NULL;

void GuiApplication::initialize(int argc, char** argv) {
	Application::initialize(argc, argv);
}

MainWindow* GuiApplication::getCurrentMainWindow() {
	return GuiApplication::_currentMainWindow;
}
void GuiApplication::setCurrentMainWindow(MainWindow* value) {
	GuiApplication::_currentMainWindow = value;
}

MainWindow* GuiApplication::getMainWindowForQMainWindow(QFXMainWindow* mainWindow) {
	MainWindow* mw = GuiApplication::_mainWindowsForQMainWindow->get(mainWindow);
	return mw;
}
void GuiApplication::setMainWindowForQMainWindow(QFXMainWindow* key, MainWindow* value) {
	GuiApplication::_mainWindowsForQMainWindow->set(key, value);
}

void GuiApplication::addPanel(Panel* item) {
	GuiApplication::_panels->add(item);
}
List<Panel*>* GuiApplication::getPanelsList() {
	return GuiApplication::_panels;
}

Panel* GuiApplication::getPanel(String* id) {
	return GuiApplication::getPanel(id->toCharArray());
}
Panel* GuiApplication::getPanel(const char* id) {
	List<Panel*>* list = GuiApplication::getPanelsList();
	for (int i = 0; i < list->count(); i++)
	{
		Panel* panel = list->get(i);
		if (panel->getID()->equals(id)) return panel;
	}
	return NULL;
}

void GuiApplication::addPerspective(Perspective* item) {
	GuiApplication::getPerspectivesList()->add(item);
}
List<Perspective*>* GuiApplication::getPerspectivesList() {
	return GuiApplication::_perspectives;
}

Perspective* GuiApplication::getPerspective(String* id) {
	return GuiApplication::getPerspective(id->toCharArray());
}
Perspective* GuiApplication::getPerspective(const char* id) {
	List<Perspective*>* list = GuiApplication::getPerspectivesList();
	for (int i = 0; i < list->count();i++)
	{
		Perspective* item = list->get(i);
		if (item->getID()->equals(id)) return item;
	}
	return NULL;
}

Perspective* GuiApplication::getDefaultPerspective() {
	return GuiApplication::_defaultPerspective;
}
void GuiApplication::setDefaultPerspective(Perspective* value) {
	GuiApplication::_defaultPerspective = value;
}

void GuiApplication::start() {
}

} /* namespace UserInterface */
} /* namespace ApplicationFramework */
