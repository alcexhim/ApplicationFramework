/*
 * Application.cpp
 *
 *  Created on: Apr 6, 2016
 *      Author: beckermj
 */

#include "Application.h"

namespace ApplicationFramework {

List<Command*>* Application::_commands;
List<CommandItem*>* Application::_mainMenuCommandItems;
Dictionary<Command*, List<void(*)(Command*)>*>* Application::_commandBindings;

int Application::_argc;
char** Application::_argv;

String* Application::_title = String::EMPTY;

void Application::initialize(int argc, char** argv) {
	Application::_argc = argc;
	Application::_argv = argv;

	Application::_commands = new List<Command*>();
	Application::_mainMenuCommandItems = new List<CommandItem*>();
	Application::_commandBindings = new Dictionary<Command*, List<void(*)(Command*)>*>();
}

void Application::addCommand(Command* item) {
	Application::_commands->add(item);
}
Command* Application::getCommand(const char* name) {
	for (int i = 0; i < Application::_commands->count(); i++)
	{
		Command* item = Application::_commands->get(i);
		if (item->getID()->equals(name)) return item;
	}
	return NULL;
}
Command* Application::getCommand(String* name) {
	return Application::getCommand(name->toCharArray());
}

bool Application::executeCommand(Command* item) {
	if (item == NULL) return false;

	if (item->getID()->equals("FileExit"))
	{
		exit(0);
		return true;
	}

	List<void(*)(Command*)>* list = Application::_commandBindings->get(item);
	if (list != NULL)
	{
		for (int i = 0; i < list->count(); i++)
		{
			list->get(i)(item);
		}
		return true;
	}
	return false;
}

void Application::addMainMenuCommandItem(CommandItem* item) {
	Application::_mainMenuCommandItems->add(item);
}
List<CommandItem*>* Application::getMainMenuCommandItemsList() {
	return Application::_mainMenuCommandItems;
}

void Application::bindCommand(Command* item, void (*callback)(Command* command)) {
	if (item == NULL) {
		printf("Application::bindCommand() - item is null\n");
		return;
	}
	List<void(*)(Command*)>* bindings = Application::_commandBindings->get(item);
	if (bindings == NULL)
	{
		bindings = new List<void(*)(Command*)>();

		Application::_commandBindings->add(item, bindings);
	}
	bindings->add(callback);
}

String* Application::getTitle() {
	return Application::_title;
}
void Application::setTitle(String* value) {
	Application::_title = value;
}

} /* namespace ApplicationFramework */
