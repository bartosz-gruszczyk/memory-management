cmake_minimum_required(VERSION 3.10)
project(MyUniquePtr)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(.)

add_executable(${PROJECT_NAME} myuniqueptr.cpp main.cpp)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -pedantic)
