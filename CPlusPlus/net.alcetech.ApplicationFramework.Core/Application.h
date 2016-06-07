/*
 * Application.h
 *
 *  Created on: Apr 6, 2016
 *      Author: beckermj
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "Collections/Generic/Dictionary.h"
#include "Collections/Generic/List.h"
#include "Command.h"
#include "CommandItem.h"

#include <stdlib.h>
#include <string.h>

using ApplicationFramework::Collections::Generic::Dictionary;
using ApplicationFramework::Collections::Generic::List;

namespace ApplicationFramework {

class Application {
private:
	static List<Command*>* _commands;
	static List<CommandItem*>* _mainMenuCommandItems;

	static int _argc;
	static char** _argv;

	static String* _title;
public:
	static Dictionary<Command*, List<void(*)(Command*)>*>* _commandBindings;

	static void initialize(int argc, char** argv);

	static void addCommand(Command* item);

	static Command* getCommand(const char* name);
	static Command* getCommand(String* name);

	static bool executeCommand(Command* item);

	static void bindCommand(Command* item, void (*callback)(Command* command));

	static void addMainMenuCommandItem(CommandItem* item);
	static List<CommandItem*>* getMainMenuCommandItemsList();

	static String* getTitle();
	static void setTitle(String* value);
};

} /* namespace ApplicationFramework */

#endif /* APPLICATION_H_ */
