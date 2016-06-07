/*
 * CommandBar.h
 *
 *  Created on: Apr 19, 2016
 *      Author: beckermj
 */

#ifndef COMMANDBAR_H_
#define COMMANDBAR_H_

#include <Collections/Generic/List.h>
#include <CommandItem.h>
#include <Property.h>
#include <String.h>

using ApplicationFramework::Collections::Generic::List;
using ApplicationFramework::CommandItem;

namespace ApplicationFramework {
namespace UserInterface {

class CommandBar {

	AFX_PROPERTY(String*, ID);
	AFX_PROPERTY(String*, Title);
	AFX_PROPERTY_READONLY(List<CommandItem*>*, ItemsList);

public:
	CommandBar();
	virtual ~CommandBar();

	void addItem(CommandItem* item);
};

} /* namespace UserInterface */
} /* namespace ApplicationFramework */

#endif /* COMMANDBAR_H_ */
