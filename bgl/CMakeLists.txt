cmake_minimum_required(VERSION 3.20)
project(BGLExample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED)

add_compile_definitions(DATASET_DIR="${CMAKE_CURRENT_LIST_DIR}/../datasets")


# main_example
add_executable(main_example src/main_example.cpp)
target_include_directories(main_example PRIVATE ${Boost_INCLUDE_DIRS})
# target_compile_definitions(main_example PRIVATE DATASET_DIR="${CMAKE_CURRENT_LIST_DIR}/../datasets")

# main_100
add_executable(main_100 src/main_100.cpp)
target_include_directories(main_100 PRIVATE ${Boost_INCLUDE_DIRS})
# target_compile_definitions(main_100 PRIVATE DATASET_DIR="${CMAKE_CURRENT_LIST_DIR}/../datasets")

# main_1000
add_executable(main_1000 src/main_1000.cpp)
target_include_directories(main_1000 PRIVATE ${Boost_INCLUDE_DIRS})
# target_compile_definitions(main_1000 PRIVATE DATASET_DIR="${CMAKE_CURRENT_LIST_DIR}/../datasets")

# main_100000
add_executable(main_100000 src/main_100000.cpp)
target_include_directories(main_100000 PRIVATE ${Boost_INCLUDE_DIRS})
# target_compile_definitions(main_100000 PRIVATE DATASET_DIR="${CMAKE_CURRENT_LIST_DIR}/../datasets")
