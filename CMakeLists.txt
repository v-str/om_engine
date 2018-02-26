cmake_minimum_required (VERSION 3.0)

set (CMAKE_INCLUDE_CURRENT_DIR ON)
set (CMAKE_CXX_STANDARD 14)
set (CMAKE_AUTOMOC ON)

set (LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})

find_package (Qt5Widgets REQUIRED)
find_package (Qt5Gui)
find_package (Qt5Core)

include ("${CMAKE_CURRENT_SOURCE_DIR}/cmake_scripts/ccache.cmake")
include ("${CMAKE_CURRENT_SOURCE_DIR}/cmake_scripts/compiler_flags.cmake")
include ("${CMAKE_CURRENT_SOURCE_DIR}/cmake_scripts/recursive_directory_function.cmake")

header_directories (LIB_HEADERS)
include_directories ("${LIB_HEADERS}")

file (GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library (om_engine_library STATIC ${SOURCES} ${RESOURCES})
qt5_use_modules (om_engine_library Widgets)
