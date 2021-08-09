cmake_minimum_required(VERSION 3.5)

project(LIMEGUI VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_subdirectory(Bridge)
add_subdirectory(Menu_Backend)
add_subdirectory(Menu_Frontend)

find_package(QT NAMES Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        logo.qrc
)

add_executable(LIMEGUI ${PROJECT_SOURCES})

target_link_libraries(LIMEGUI PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Bridge Backend Frontend)