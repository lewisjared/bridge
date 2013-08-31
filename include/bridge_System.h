/*
 * bridgesystem.h
 *
 *  Created on: 30/08/2013
 *      Author: jared
 */

#ifndef BRIDGE_SYSTEM_H_
#define BRIDGE_SYSTEM_H_

#include <string>

namespace bridge
{

class System {
public:
	static void initialise();
	static void destroy();
	System* getInstance();

protected:
	System();
	~System();
	static System* m_instance;

	virtual void setUp() = 0;
	virtual void tearDown() = 0;
public:

	//Things to include
	//  clipboard

	virtual std::string getClipboard() = 0;
	virtual void setClipboard(std::string str) = 0;
};
}

#endif /* BRIDGESYSTEM_H_ */
