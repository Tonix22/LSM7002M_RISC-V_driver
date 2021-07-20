cmake_minimum_required(VERSION 3.1.0)
project(Bridge VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Debug)

set(IPDI_WIN "C:/ipdi")
set(QTMW "${IPDI_WIN}/wrappers/Qt")
set(LMW "${IPDI_WIN}/base")

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

set(CMAKE_PREFIX_PATH "E:/Qt/5.15.1/mingw81_64")
set(Qt5_DIR "${CMAKE_PREFIX_PATH}/lib/cmake/Qt5")
set(Qt5Widgets_DIR "${CMAKE_PREFIX_PATH}/lib/cmake/Qt5Widgets")
set(Qt5Network_DIR "${CMAKE_PREFIX_PATH}/lib/cmake/Qt5Network")
set(Qt5LinguistTools_DIR "${CMAKE_PREFIX_PATH}/lib/cmake/Qt5LinguistTools")

find_package(Qt5 COMPONENTS Widgets REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(Bridge Server.cpp bridge.cpp COM_finder.cpp)

target_link_libraries(Bridge PRIVATE Qt5::Widgets -L${QTMW}/lib/ -lqtmw -L${LMW}/lib/ -lmw -lshlwapi)

target_include_directories (Bridge PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../QT_cmake ${QTMW}/include ${LMW}/include)