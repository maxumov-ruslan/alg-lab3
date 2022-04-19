project(lab3-asd)
cmake_minimum_required(VERSION 3.12)   
option(BUILD_TESTS "Build test" ON)

add_executable(task1 task1.cpp lis.cpp lis.hpp catch.hpp) 
add_executable(task2 task2.cpp parens.cpp parens.hpp)

if(BUILD_TESTS)
  enable_testing()
  add_executable(test1 test.cpp lis.cpp lis.hpp parens.cpp parens.hpp catch.hpp) 
  add_test(test1 test1) 
endif()
