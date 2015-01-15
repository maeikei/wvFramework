project(watorvapor)
cmake_minimum_required(VERSION 2.8)
#include_directories(${PROJECT_SOURCE_DIR}/3rdpartbuiltin/leveldb-1.9.0/include)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")


#add_subdirectory(3rdpartbuiltin)
add_subdirectory(framework)
add_subdirectory(client/wvmake)
