cmake_minimum_required(VERSION 2.8...3.15)

if (${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

set (CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)

project(CopmuterNetworks)

enable_testing()

include_directories(include)
add_subdirectory(src)

message("Source files: " ${SRC})

set (LIBS
  pthread
)

add_executable(example example.cpp src/frameio2.cpp src/util.cpp)
target_link_libraries(example ${LIBS})

add_executable(stack main.cpp)
target_link_libraries(stack ${LIBS} src_lib)

add_executable(tcp_test tcp_test.cpp)
target_link_libraries(tcp_test ${LIBS})

add_executable(test_chksum test_chksum.cpp)
target_link_libraries(test_chksum ${LIBS})
