cmake_minimum_required(VERSION 3.13.4)
project(AlphaInfection VERSION 0.1.0)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

# set the C++17 standard
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS OFF)
# set(CMAKE_CXX_FLAGS "-DLOG_USE_COLOR")

include(CTest)
enable_testing()

set(CMAKE_MODULE_PATH
	${CMAKE_MODULE_PATH}
	"${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules")

find_package(Boost 1.70 REQUIRED)
find_package(Config++ REQUIRED)
find_package(SDL2 2.0.10 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories("includes"
	${SDL2_INCLUDE_DIRS}
	${SDL2_IMAGE_INCLUDE_DIRS}
	${SDL2_TTF_INCLUDE_DIRS}
	${Boost_INCLUDE_DIR}
	${CONFIG++_INCLUDE_DIR})


add_library(aiEngine SHARED src/engine.cxx)
target_link_libraries(aiEngine
	${SDL2_LIBRARY}
	${SDL2_IMAGE_LIBRARIES}
	${SDL2_TTF_LIBRARIES}
	-v)

add_library(aiGame SHARED src/game.cxx)
add_executable(AlphaInfection src/main.cxx)
target_link_libraries(AlphaInfection
	aiGame
	aiEngine
	${Boost_LIBRARIES}
	${CONFIG++_LIBRARY}
	-v)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
