/*
 * Command.h
 *
 *  Created on: Apr 6, 2016
 *      Author: beckermj
 */

#ifndef COMMAND_H_
#define COMMAND_H_

#include "Collections/Generic/List.h"
#include "Collections/Generic/Dictionary.h"
#include "CommandItem.h"
#include "Shortcut.h"
#include "Object.h"

using ApplicationFramework::Collections::Generic::List;
using ApplicationFramework::Collections::Generic::Dictionary;

namespace ApplicationFramework {

class Command {
private:
	String* _ID;
	String* _title;
	List<CommandItem*>* _commandItems;
	Shortcut* _shortcut;
	Dictionary<String*, Object*>* _extraData;
public:
	Command();
	virtual ~Command();

	String* getID();
	void setID(String* value);

	String* getTitle();
	void setTitle(String* value);

	void addCommandItem(CommandItem* item);
	List<CommandItem*>* getCommandItemsList();

	Shortcut* getShortcut();
	void setShortcut(Shortcut* value);

	Object* getExtraData(const char* key);
	Object* getExtraData(String* key);
	void setExtraData(const char* key, Object* value);
	void setExtraData(String* key, Object* value);
};

} /* namespace ApplicationFramework */

#endif /* COMMAND_H_ */
