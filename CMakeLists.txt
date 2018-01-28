cmake_minimum_required(VERSION 3.0)

set (PROJECT_NAME om_engine)
project(${PROJECT_NAME})

set (CMAKE_INCLUDE_CURRENT_DIR ON)
set (CMAKE_CXX_STANDARD 14)
set (CMAKE_AUTOMOC ON)

set (LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})

find_package (Qt5Widgets REQUIRED)
find_package (Qt5Gui)
find_package (Qt5Core)

include ("${CMAKE_CURRENT_SOURCE_DIR}/cmake/ccache.cmake")
include ("${CMAKE_CURRENT_SOURCE_DIR}/cmake/compiler_flags.cmake")
include ("${CMAKE_CURRENT_SOURCE_DIR}/cmake/recursive_directory_function.cmake")

add_subdirectory (om_engine_library)

header_directories (OM_ENGINE_HEADERS)
include_directories ("${OM_ENGINE_HEADERS}")

include_directories ("${CMAKE_CURRENT_SOURCE_DIR}/third_party")

file (GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
file (GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

qt5_add_resources (RESOURCES om_engine_resources.qrc)

set (TXT_FILES "${CMAKE_CURRENT_SOURCE_DIR}/third_party/to_do_list"
               "${CMAKE_CURRENT_SOURCE_DIR}/third_party/documentation"
               "${CMAKE_CURRENT_SOURCE_DIR}/third_party/code_style")

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} ${RESOURCES} ${TXT_FILES})
target_link_libraries (${PROJECT_NAME} om_engine_library)
