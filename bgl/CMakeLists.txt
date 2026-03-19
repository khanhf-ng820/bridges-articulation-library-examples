cmake_minimum_required(VERSION 3.20)
project(BGLExample)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED)

add_executable(main src/main.cpp)

target_include_directories(main PRIVATE ${Boost_INCLUDE_DIRS})
