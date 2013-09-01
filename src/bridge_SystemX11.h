/*
 * bridge_SystemX11.h
 *
 *  Created on: 31/08/2013
 *      Author: jared
 */

#ifndef BRIDGE_SYSTEMX11_H_
#define BRIDGE_SYSTEMX11_H_

#include "bridge_System.h"

#include "X11/Xlib.h"
#include <string>

namespace bridge
{
	class SystemX11: public System {
	protected:
		SystemX11();
		~SystemX11();
		void setUp();
		void tearDown();
	public:
		std::string getClipboard();
		void setClipboard(std::string str);
		bool processEvents();

	private:
		Display* m_display;
		void interpretEvent(XEvent* event);
	};
}

#endif /* BRIDGE_SYSTEMX11_H_ */
