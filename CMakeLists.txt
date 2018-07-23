cmake_minimum_required(VERSION 3.0.0)
project(AlphaInfection VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(aicore STATIC alpha_infection.c)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
# find_package(SDL2_image REQUIRED)
# find_package(SDL2_ttf REQUIRED)

add_executable(AlphaInfection main.c)
target_link_libraries(AlphaInfection aicore ${SDL2_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
