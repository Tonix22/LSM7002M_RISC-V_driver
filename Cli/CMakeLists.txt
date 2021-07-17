cmake_minimum_required(VERSION 3.1.0)

set(CMAKE_CXX_STANDARD 11)

add_executable(basicTX basicTX.cpp)
set_target_properties(basicTX PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../executables")
target_link_libraries(basicTX LimeSuite)

add_executable(basicRX basicRX.cpp)
set_target_properties(basicRX PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../executables")
target_link_libraries(basicRX LimeSuite)

add_executable(basicRXTX dualRXTX.cpp)
set_target_properties(basicRXTX PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../executables")
target_link_libraries(basicRXTX LimeSuite)

add_executable(singleRX singleRX.cpp)
set_target_properties(singleRX PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../executables")
target_link_libraries(singleRX LimeSuite)