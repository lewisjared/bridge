project(bridge)

CMAKE_MINIMUM_REQUIRED (VERSION 2.6.2)

#Create a list of source files
set (SOURCE_FILES	
	src/bridge_Event.cpp
	src/bridge_System.cpp
)

set (INC_DIR
	./include
	./src
)

#Conditionally add src files depending on OS
IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	list(APPEND SOURCE_FILES
		src/bridge_SystemX11.cpp
	)
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	list(APPEND SOURCE_FILES
		src/bridge_SystemWin32.cpp
	)
endif ()


#build the library
include_directories( ./include )
include_directories(./src )
add_library(bridge STATIC ${SOURCE_FILES} )
