SET(CONFIG++_SEARCH_PATHS
	~/Library/Frameworks
	/Library/Frameworks
	/usr/local
	/usr
	/sw # Fink
	/opt/local # DarwinPorts
	/opt/csw # Blastwave
	/opt
	${VCPKG_PATH}
)

FIND_PATH(CONFIG++_INCLUDE_DIR libconfig.h++
	HINTS
    PATH_SUFFIXES include
    PATHS ${CONFIG++_SEARCH_PATHS}
)

if (CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(VC_LIB_PATH_SUFFIX lib/x64)
else ()
    set(VC_LIB_PATH_SUFFIX lib/x86)
endif ()

FIND_LIBRARY(CONFIG++_LIBRARY
    NAMES libconfig++ libconfig++.a libconfig.so
    HINTS
    PATH_SUFFIXES lib ${VC_LIB_PATH_SUFFIX}
    PATHS ${CONFIG++_SEARCH_PATHS}
)

IF (CONFIG++_INCLUDE_DIR AND CONFIG++_LIBRARY)
    SET(CONFIG++_FOUND TRUE)
ENDIF (CONFIG++_INCLUDE_DIR AND CONFIG++_LIBRARY)

IF (CONFIG++_FOUND)
    IF (NOT CONFIG++_FIND_QUIETLY)
	MESSAGE(STATUS "Found Config++: ${CONFIG++_LIBRARY}")
    ENDIF (NOT  CONFIG++_FIND_QUIETLY)
ELSE(CONFIG++_FOUND)
    IF (Config++_FIND_REQUIRED)
	    IF(NOT CONFIG++_INCLUDE_DIR)
	        MESSAGE(FATAL_ERROR "Could not find LibConfig++ header file!")
	    ENDIF(NOT CONFIG++_INCLUDE_DIR)

	    IF(NOT CONFIG++_LIBRARY)
	        MESSAGE(FATAL_ERROR "Could not find LibConfig++ library file!")
	    ENDIF(NOT CONFIG++_LIBRARY)
    ENDIF (Config++_FIND_REQUIRED)
ENDIF (CONFIG++_FOUND)