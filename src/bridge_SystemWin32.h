/*
 * SystemWin32.h
 *
 *  Created on: 30/08/2013
 *      Author: jared
 */

#ifndef BRIDGE_SYSTEMWIN32_H_
#define BRIDGE_SYSTEMWIN32_H_

#include "bridge_System.h"

namespace bridge
{

class SystemWin32 : public System{
protected:
	SystemWin32();
	~SystemWin32();

	void setUp();
	void tearDown();
public:
	std::string getClipboard();
	void setClipboard(std::string str);
};

}

#endif /* SYSTEMWIN32_H_ */
