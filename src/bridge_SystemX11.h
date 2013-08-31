/*
 * bridge_SystemX11.h
 *
 *  Created on: 31/08/2013
 *      Author: jared
 */

#ifndef BRIDGE_SYSTEMX11_H_
#define BRIDGE_SYSTEMX11_H_

#include "bridge_System.h"

namespace bridge
{
	class SystemX11: public System {
	protected:
		void setUp();
		void tearDown();
	public:
		std::string getClipboard();
		void setClipboard(std::string str);
	};
}

#endif /* BRIDGE_SYSTEMX11_H_ */
