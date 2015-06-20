project(p3signals)

cmake_minimum_required(VERSION 2.8.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(${p3signals_SOURCE_DIR}/src)

include_directories(${p3signals_SOURCE_DIR}/src/include)
find_package(CppUnit)

add_subdirectory(${p3signals_SOURCE_DIR}/tests)
