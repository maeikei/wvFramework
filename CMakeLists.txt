project(watorvapor)
cmake_minimum_required(VERSION 2.8)
#include_directories(${PROJECT_SOURCE_DIR}/3rdpartbuiltin/leveldb-1.9.0/include)
include_directories(${PROJECT_SOURCE_DIR}/framework/include)
add_definitions(-DBOOST_LOG_DYN_LINK)


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -pthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -std=c++11 -pthread")


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")


#add_subdirectory(3rdpartbuiltin)
add_subdirectory(framework)
add_subdirectory(wator)
#add_subdirectory(client/wvmake)
