cmake_minimum_required(VERSION 3.15)

project(guess_homework CXX)

add_executable(guess_homework
	check_value.cpp
  random_value.h
	random_value.cpp
)

set_target_properties(guess_homework PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
  CMAKE_CXX_COMPILER_ID STREQUAL "GNU")

    target_compile_options(guess_homework PRIVATE -Wall -Wextra -Werror -pedantic)

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")

    target_compile_options(guess_homework PRIVATE /EHsc /W3)

endif()