/*
 * bridgesystem.cpp
 *
 *  Created on: 30/08/2013
 *      Author: jared
 */

#include "bridge_System.h"


using namespace bridge;

System::System() {
	m_eventManager = new EventManager;
}

System::~System() {
	delete m_eventManager;
}

System* System::getInstance()
{
	return m_instance;
}

void System::initialise()
{
	if (!m_instance)
	{
	#ifdef WIN32
		m_instance = new SystemWin32();
	#elif X11
		m_instance = new SystemX11();
	#endif
	}

	if (m_instance)
		m_instance->setUp();
}

void System::destroy()
{
	if (m_instance)
	{
		m_instance->tearDown();

		delete m_instance;
	}
}

void System::handleEvents()
{
	m_eventManager->handleEvents();
}

