/*
 * bridge_Event.cpp
 *
 *  Created on: 30/08/2013
 *      Author: jared
 */

#include "bridge_Event.h"

using namespace bridge;

Event::Event(TEventType type, TEventData data)
	: m_type(type), m_data(data)
{
}

Event::~Event()
{
}

TEventType Event::getType()
{
	return m_type;
}

TEventData Event::getData()
{
	return m_data;
}
