/*
 * bridge_EventManager.cpp
 *
 *  Created on: 1/09/2013
 *      Author: jared
 */

#include "bridge_EventManager.h"

namespace bridge {

EventManager::~EventManager() {
	// TODO Auto-generated destructor stub
}

EventManager::EventManager() {
	// TODO Auto-generated constructor stub

}

bool EventManager::handleEvent()
{
	Event* event = popEvent();

	// Go through the handlers

	delete event;

	return true;

}

void EventManager::handleEvents()
{
	while( getNumEvents())
		handleEvent();
}

void EventManager::pushEvent(Event* event)
{
	m_eventStack.push_back(event);
}

Event* EventManager::popEvent()
{
	Event* event = m_eventStack.front();
	m_eventStack.pop_front();

	return event;
}

size_t EventManager::getNumEvents()
{
	return m_eventStack.size();
}

} /* namespace bridge */
