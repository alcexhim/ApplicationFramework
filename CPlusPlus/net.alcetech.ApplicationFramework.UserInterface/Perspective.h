/*
 * Perspective.h
 *
 *  Created on: Apr 10, 2016
 *      Author: beckermj
 */

#ifndef PERSPECTIVE_H_
#define PERSPECTIVE_H_

#include <Collections/Generic/List.h>
#include <String.h>
#include <Property.h>

#include "CommandBar.h"
#include "PanelArea.h"

#include <Object.h>

using ApplicationFramework::Collections::Generic::List;

namespace ApplicationFramework {
namespace UserInterface {

class Perspective : public Object {

	AFX_PROPERTY(String*, ID);
	AFX_PROPERTY(String*, Title);

	AFX_PROPERTY_READONLY(List<CommandBar*>*, CommandBarsList);
	AFX_PROPERTY_READONLY(List<PanelArea*>*, PanelAreasList);

public:
	Perspective();
	virtual ~Perspective();

	void addPanelArea(PanelArea* item);
	void addCommandBar(CommandBar* item);
};

} /* namespace UserInterface */
} /* namespace ApplicationFramework */

#endif /* PERSPECTIVE_H_ */
