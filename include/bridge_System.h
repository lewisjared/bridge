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

	void setUp() = 0;
	void tearDown() = 0;
public:

	//Things to include
	//  clipboard

	std::string getClipboard() = 0;
	void setClipboard(std::string str) = 0;
};
}

#endif /* BRIDGESYSTEM_H_ */
