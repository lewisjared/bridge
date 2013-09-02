/*
 * bridge_EventManager.h
 *
 *  Created on: 1/09/2013
 *      Author: jared
 */

#ifndef BRIDGE_EVENTMANAGER_H_
#define BRIDGE_EVENTMANAGER_H_

#include "bridge_Event.h"

#include <cstring>
#include <deque>

namespace bridge {

/**
 *
 */
class EventManager {
public:
	virtual ~EventManager();
	EventManager();

	bool handleEvent();
	void handleEvents();

	/*
	 * This class takes ownership of this event
	 */
	void pushEvent(Event* event);

	/*
	 * Pops event from thefront of the queue
	 * The class gives ownership of the event
	 */
	Event* popEvent();

	size_t getNumEvents();

private:
	typedef std::deque<Event *> TEventStack;
	TEventStack m_eventStack;
};

} /* namespace bridge */
#endif /* BRIDGE_EVENTMANAGER_H_ */
