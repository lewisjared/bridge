/*
 * bridge_Event.h
 *
 *  Created on: 30/08/2013
 *      Author: jared
 */

#ifndef BRIDGE_EVENT_H_
#define BRIDGE_EVENT_H_

#include "bridge_Types.h"

namespace bridge
{
	class Event {
	public:
		Event(TEventType type, TEventData data);
		virtual ~Event();

		TEventData getData();
		TEventType getType();

	protected:
		TEventType m_type;
		TEventData m_data;
	};
}

#endif /* BRIDGE_EVENT_H_ */
