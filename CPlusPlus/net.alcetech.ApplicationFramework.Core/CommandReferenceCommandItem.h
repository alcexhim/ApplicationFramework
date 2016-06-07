/*
 * CommandReferenceCommandItem.h
 *
 *  Created on: Apr 2, 2016
 *      Author: beckermj
 */

#ifndef COMMANDREFERENCECOMMANDITEM_H_
#define COMMANDREFERENCECOMMANDITEM_H_

#include "CommandItem.h"
#include "String.h"

namespace ApplicationFramework {

class CommandReferenceCommandItem : public CommandItem {
private:
	String* _commandID;
public:
	CommandReferenceCommandItem();
	CommandReferenceCommandItem(const char* commandID);
	CommandReferenceCommandItem(String* commandID);
	virtual ~CommandReferenceCommandItem();

	String* getCommandID();
	void setCommandID(String* value);
};

} /* namespace ApplicationFramework */

#endif /* COMMANDREFERENCECOMMANDITEM_H_ */
