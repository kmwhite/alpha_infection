cmake_minimum_required(VERSION 3.13.4)
project(AlphaInfection VERSION 0.1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)

#set(VCPKG_PATH "C:\\Users\\me\\Downloads\\vcpkg-2020.06\\vcpkg-2020.06\\installed\\x86-windows\\")
#set(BOOST_ROOT "C:\\Users\\me\\Downloads\\vcpkg-2020.06\\vcpkg-2020.06\\installed\\x86-windows\\include")

# set the C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# control where the static and shared libraries are built so that on windows
# we don't need to tinker with the path to run the executable
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_EXE_LINKER_FLAGS "-static")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -Werror -Wdeprecated")

set(CMAKE_EXPORT_COMPILE_COMMANDS OFF)
# set(CMAKE_CXX_FLAGS "-DLOG_USE_COLOR")

include(CTest)
enable_testing()

set(CMAKE_MODULE_PATH
	${CMAKE_MODULE_PATH}
	"${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules")

find_package(Boost 1.67 REQUIRED)
find_package(fmt REQUIRED)
find_package(SDL2 2.0.10 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

# FIXME: https://github.com/hyperrealm/libconfig/issues/106
find_package(Config++ REQUIRED)

include_directories("includes"
	${SDL2_INCLUDE_DIRS}
	${SDL2_IMAGE_INCLUDE_DIRS}
	${SDL2_TTF_INCLUDE_DIRS}
	${Boost_INCLUDE_DIR}
	${CONFIG++_INCLUDE_DIR})

add_library(aiLogger src/logger.cxx)

add_library(aiEngine src/engine.cxx)
target_link_libraries(aiEngine
	${Boost_LIBRARIES}
	${SDL2_LIBRARY}
	${SDL2_IMAGE_LIBRARIES}
	${SDL2_TTF_LIBRARIES}
	aiLogger -static)

add_library(aiGame src/game.cxx)
target_link_libraries(aiGame
	${Boost_LIBRARIES}
	${SDL2_LIBRARY}
	${SDL2_IMAGE_LIBRARIES}
	${SDL2_TTF_LIBRARIES}
	${CONFIG++_LIBRARY}
	fmt::fmt
	aiLogger -static)

add_executable(AlphaInfection src/main.cxx)
target_link_libraries(AlphaInfection
	${SDL2_LIBRARY}
	${SDL2_IMAGE_LIBRARIES}
	${SDL2_TTF_LIBRARIES}
	${Boost_LIBRARIES}
	${CONFIG++_LIBRARY}
	aiLogger
	aiGame
	aiEngine -static)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
