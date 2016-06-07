/*
 * PanelArea.h
 *
 *  Created on: Apr 12, 2016
 *      Author: beckermj
 */

#ifndef PANELAREA_H_
#define PANELAREA_H_

#include <Collections/Generic/List.h>

#include "PanelReference.h"
#include "PanelAreaLocation.h"

using ApplicationFramework::Collections::Generic::List;

using ApplicationFramework::UserInterface::PanelAreaLocation;

namespace ApplicationFramework {
namespace UserInterface {

class PanelArea {
private:
	PanelAreaLocation _location;
	List<PanelBase*>* _panelsList;
public:
	PanelArea();
	virtual ~PanelArea();

	PanelAreaLocation getLocation();
	void setLocation(PanelAreaLocation value);

	void addPanel(PanelBase* item);
	List<PanelBase*>* getPanelsList();
};

} /* namespace UserInterface */
} /* namespace ApplicationFramework */

#endif /* PANELAREA_H_ */
