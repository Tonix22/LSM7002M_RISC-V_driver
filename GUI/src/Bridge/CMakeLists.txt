cmake_minimum_required(VERSION 3.1.0)
# Defines the name and language the project will be using.
project(Bridge LANGUAGES CXX)

set(CMAKE_PREFIX_PATH "E:\\QT\\5.15.2\\msvc2019_64\\lib\\cmake")
set(QT_QMAKE_EXECUTABLE "E:\\QT\\5.15.2\\msvc2019_64\\bin")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the path to the Qt5 installation's CMake instructions.
set(Qt5_DIR "E:/QT/5.15.2/msvc2019_64/lib/cmake/Qt5")

set(Qt5Core_DIR "E:/QT/5.15.2/msvc2019_64/lib/cmake/Qt5Core")
set(QT5Gui_DIR "E:/QT/5.15.2/msvc2019_64/lib/cmake/Qt5Gui")
set(Qt5Widgets_DIR "E:/QT/5.15.2/msvc2019_64/lib/cmake/Qt5Widgets")

set(QT_QMAKE_EXECUTABLE "E:/QT/5.15.2/msvc2019_64/bin/qmake.exe")


set(IPDI_WIN "C:/ipdi")
set(QTMW "${IPDI_WIN}/wrappers/Qt")
set(LMW "${IPDI_WIN}/base")

# Automatically add the current source and build directories to the
# include path.
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


include(GenerateExportHeader)

# Include Qt5 and its widgets.
find_package(Qt5 HINTS COMPONENTS Core Widgets Gui REQUIRED)
get_directory_property(_vars VARIABLES)

list(REMOVE_ITEM _vars _vars_before ${_vars_before})
foreach(_var IN LISTS _vars)
    message(STATUS "${_var} = ${${_var}}")
endforeach()

add_library(Bridge bridge.cpp COM_finder.cpp)

#target_link_libraries(Bridge Qt5::Widgets ${QTMW}/lib/ -lqtmw ${LMW}/lib/ -lmw -lshlwapi)
target_link_libraries(Bridge PUBLIC Qt5::Core Qt5::Gui Qt5::Widgets)

target_include_directories (Bridge PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${QTMW}/include ${LMW}/include)
