cmake_minimum_required(VERSION 2.8...3.15)

if (${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

message("src directory")

file (GLOB SRC
  *.cpp)

add_library(src_lib OBJECT ${SRC})
