#include "ACBuilder.hpp"
using namespace wator::ac;
#include "debug.h"

#include <list>
#include <boost/algorithm/string.hpp>
/*
project({name})
cmake_minimum_required(VERSION 2.8)
include_directories({root})
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -pthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -std=c++11 -pthread")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
*/

ACBuilder::ACBuilder(const fs::path &root)
:cmake_()
{
  cmake_ += "project(";
  cmake_ += root.leaf().string();
  cmake_ += ")\n";
  cmake_ += "cmake_minimum_required(VERSION 2.8)\n";
  cmake_ += "include_directories(";
  cmake_ += root.string();
  cmake_ += ")\n";
  cmake_ += "set(CMAKE_C_FLAGS \"${CMAKE_C_FLAGS} -std=c11 -pthread\")\n";
  cmake_ += "set(CMAKE_CXX_FLAGS \"${CMAKE_CXX_FLAGS} -std=c++11 -pthread\")\n";
  cmake_ += "set(CMAKE_EXE_LINKER_FLAGS \"${CMAKE_EXE_LINKER_FLAGS} -std=c++11 -pthread\")\n";
  cmake_ += "set(CMAKE_C_FLAGS \"${CMAKE_C_FLAGS} -Wall\")\n";
  cmake_ += "set(CMAKE_CXX_FLAGS \"${CMAKE_CXX_FLAGS} -Wall\")\n";

}
bool ACBuilder::gen(void)
{
  LOG_INFO(cmake_);
  return true;
}
