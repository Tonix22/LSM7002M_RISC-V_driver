cmake_minimum_required(VERSION 3.1.0)
project(Frontend VERSION 1.0.0 LANGUAGES CXX)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_library(Frontend description.cpp)

target_link_libraries(Frontend Qt5::Widgets LIMEGUI Bridge Backend)

target_include_directories (Frontend PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../ 
${CMAKE_CURRENT_SOURCE_DIR}/../Bridge
${CMAKE_CURRENT_SOURCE_DIR}/../Menu_Backend)
