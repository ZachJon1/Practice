cmake_minimum_required(VERSION 3.1)
project(program)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(. ../include)

add_library(ipb_arithmetic subtract.cpp sum.cpp)
add_executable(main main.cpp)
target_link_libraries(main ipb_arithmetic) 

install(build/ ../../install)