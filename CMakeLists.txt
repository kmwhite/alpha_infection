cmake_minimum_required(VERSION 3.0.0)
project(AlphaInfection VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_MODULE_PATH
        ${CMAKE_MODULE_PATH}
        "${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules"
        "${CMAKE_CURRENT_SOURCE_DIR}/sdl2-cmake-scripts")

find_package(LibConfuse REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR}
        ${LIBCONFUSE_INCLUDE_DIR}       )

add_library(aiCore STATIC alpha_infection.c)
add_library(aiConfig STATIC config.c)
add_library(aiLogging STATIC logging.c)
add_library(aiUtils STATIC utils.c)


add_executable(AlphaInfection main.c)
target_link_libraries(AlphaInfection
                        aiCore
                        aiConfig
                        aiLogging
                        aiUtils
                        ${SDL2_LIBRARY}
                        ${SDL2_IMAGE_LIBRARIES}
                        ${SDL2_TTF_LIBRARIES}
                        ${LIBCONFUSE_LIBRARY})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)