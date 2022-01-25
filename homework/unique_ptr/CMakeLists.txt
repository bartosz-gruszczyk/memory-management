cmake_minimum_required(VERSION 3.10)
project(MyUniquePtr)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(.)

#GTest download
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME} myuniqueptr.cpp main.cpp)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -pedantic)

# Tests executable
add_executable(${PROJECT_NAME}-ut myuniqueptr.cpp tests.cpp)
target_link_libraries(${PROJECT_NAME}-ut gtest_main)
enable_testing()
add_test(NAME ${PROJECT_NAME}-test COMMAND ${PROJECT_NAME}-ut)
