cmake_minimum_required(VERSION 3.1.0)
project(RF_APP)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})
add_executable(LimeGUI main.cpp pnlAPI.cpp)
target_link_libraries(LimeGUI ${wxWidgets_LIBRARIES})
