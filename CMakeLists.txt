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

# Ensure that eclipse can parse GCCs output
IF(CMAKE_COMPILER_IS_GNUCC)
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fmessage-length=0")
ENDIF(CMAKE_COMPILER_IS_GNUCC)
IF(CMAKE_COMPILER_IS_GNUCXX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fmessage-length=0")
ENDIF(CMAKE_COMPILER_IS_GNUCXX)


#build the library
include_directories( ./include )
include_directories(./src )
add_library(bridge STATIC ${SOURCE_FILES} )
