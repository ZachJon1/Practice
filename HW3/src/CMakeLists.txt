cmake_minimum_required(VERSION 3.10)

project(ImageBrowserApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(fmt REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(imagebrowser image_browser.cpp html_writer.cpp)
add_executable(htmlwriter html_writer.cpp main.cpp )

target_link_libraries(imagebrowser fmt::fmt)
target_link_libraries(htmlwriter fmt::fmt)