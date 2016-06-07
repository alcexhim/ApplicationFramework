/*
 * PanelGroup.h
 *
 *  Created on: Apr 12, 2016
 *      Author: beckermj
 */

#ifndef PANELGROUP_H_
#define PANELGROUP_H_

#include <Collections/Generic/List.h>
#include "PanelBase.h"

using ApplicationFramework::Collections::Generic::List;

namespace ApplicationFramework {
namespace UserInterface {

class PanelGroup : public PanelBase {
private:
	List<PanelBase*>* _panelsList;
public:
	PanelGroup();
	virtual ~PanelGroup();

	void addPanel(PanelBase* item);
	List<PanelBase*>* getPanelsList();
};

} /* namespace UserInterface */
} /* namespace ApplicationFramework */

#endif /* PANELGROUP_H_ */
