cmake_minimum_required(VERSION 3.20)

project(Singleton)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()

add_executable(
  test_app
  test.cpp
)

target_link_libraries(
  test_app
  gtest
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_app)
