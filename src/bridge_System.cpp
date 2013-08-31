/*
 * bridgesystem.cpp
 *
 *  Created on: 30/08/2013
 *      Author: jared
 */

#include "bridge_System.h"


using namespace bridge;

System::System() {
	//Do nothing
}

System::~System() {
	//Do nothing
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

