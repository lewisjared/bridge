/*
 * bridge_SystemX11.cpp
 *
 *  Created on: 31/08/2013
 *      Author: jared
 */

#include "bridge_SystemX11.h"
#include "bridge_Event.h"

#include <stddef.h>
#include <iostream>

using namespace bridge;

SystemX11::SystemX11()
	:System()
{
	m_display = XOpenDisplay(0);

	if (m_display)
	{
		std::cout << "Could not open display" << std::endl;
	}
}

SystemX11::~SystemX11()
{
	XCloseDisplay(m_display);
}

void SystemX11::setUp()
{

}

void SystemX11::tearDown()
{

}

std::string SystemX11::getClipboard()
{
	return std::string();
}

void SystemX11::setClipboard(std::string str)
{

}

bool SystemX11::processEvents()
{
	bool anyEvents = false;

	//This function clears the event queue
	while(XPending(m_display))
	{
		//Extract the event
		XEvent event;
		XNextEvent(m_display, &event);

		//Interpret event
		interpretEvent(&event);
		anyEvents = true;
	}

	return anyEvents;
}

/*
 * Interprets an XEvent and converts it into a bridge event
 */
void SystemX11::interpretEvent(XEvent* event)
{
	Event* brgEvent = NULL;
	switch(event->type)
	{
	case KeyPress:
	case KeyRelease:
		//Create a Button Event and push

		break;

	case ButtonPress:
	case ButtonRelease:
		break;
	default:
		std::cout << "Event not handled: " << event->type << std::endl;
		break;
	}

	if (brgEvent)
		m_eventManager->pushEvent(brgEvent);
}
