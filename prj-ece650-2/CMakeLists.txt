cmake_minimum_required(VERSION 2.8)
project(prj-ece650)

if (EXISTS "${CMAKE_SOURCE_DIR}/minisat")
  add_subdirectory(minisat)
else()
  message (FATAL_ERROR "MiniSat not found. Use `git clone https://github.com/agurfinkel/minisat` to check it out.")
endif()

find_package (Threads)

# enable c++11 support
set (CMAKE_CXX_FLAGS "-std=c++11 -Wall ${CMAKE_CXX_FLAGS}")
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/run)

# expose minisat header files
include_directories(${CMAKE_SOURCE_DIR}/minisat)
LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/run)


# create the main executable
add_executable(prj-ece650 VertexCoverAlgo.cpp prj-ece650.cpp Graph.cpp)

target_link_libraries(prj-ece650 minisat-lib-static)
target_link_libraries(prj-ece650 ${CMAKE_THREAD_LIBS_INIT})
