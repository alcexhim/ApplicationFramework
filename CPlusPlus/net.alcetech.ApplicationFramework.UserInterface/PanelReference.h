/*
 * PanelReference.h
 *
 *  Created on: Apr 19, 2016
 *      Author: beckermj
 */

#ifndef PANELREFERENCE_H_
#define PANELREFERENCE_H_

#include <Property.h>
#include <String.h>

#include "PanelBase.h"

using ApplicationFramework::String;

namespace ApplicationFramework {
namespace UserInterface {

class PanelReference : public PanelBase {

	AFX_PROPERTY(String*, PanelID);

public:
	PanelReference();
	PanelReference(String* panelID);
	virtual ~PanelReference();
};

} /* namespace UserInterface */
} /* namespace ApplicationFramework */

#endif /* PANELREFERENCE_H_ */
