cmake_minimum_required (VERSION 3.0)

find_package (Qt5Widgets REQUIRED)
find_package (Qt5Gui)
find_package (Qt5Core)

header_directories (LIB_HEADERS)
include_directories ("${LIB_HEADERS}")

file (GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

qt5_add_resources (RESOURCES om_engine_resources.qrc)

add_library (om_engine_library STATIC ${SOURCES} ${RESOURCES} ${RESOURCES})
qt5_use_modules (om_engine_library Widgets)
