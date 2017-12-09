cmake_minimum_required(VERSION 3.0)

enable_testing ()

set (PROJECT_NAME om_engine)
project(${PROJECT_NAME})

set (CMAKE_INCLUDE_CURRENT_DIR ON)
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_AUTOMOC ON)

find_package (Qt5Widgets REQUIRED)
find_package (Qt5Gui)
find_package (Qt5Core)

include ("${CMAKE_CURRENT_SOURCE_DIR}/cmake/ccache.cmake")
include ("${CMAKE_CURRENT_SOURCE_DIR}/cmake/compiler_flags.cmake")
include ("${CMAKE_CURRENT_SOURCE_DIR}/cmake/recursive_directory_function.cmake")

include_directories (sources tests tests/testing_framework)
add_subdirectory (om_engine_library)

header_directories (OM_ENGINE_HEADERS)
include_directories ("${OM_ENGINE_HEADERS}")

file (GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
file (GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

set (TXT_FILES "${CMAKE_CURRENT_SOURCE_DIR}/to_do_list")

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} ${TXT_FILES})
target_link_libraries (${PROJECT_NAME} om_engine_library)

add_test (${PROJECT_NAME} ${PROJECT_NAME})
