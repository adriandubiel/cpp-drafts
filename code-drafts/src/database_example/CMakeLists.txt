cmake_minimum_required(VERSION 3.20)

project(database_example)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(
  app
  persistence_interface.cpp
  nosql_database.cpp
  main.cpp
)
