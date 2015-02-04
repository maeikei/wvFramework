#include "ACBuilder.hpp"
using namespace wator::ac;
#include "debug.h"

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

ACBuilder::ACBuilder(const std::string &root)
:output_()
{
  output_ += "project(";
  output_ += ")\n";
  output_ += "cmake_minimum_required(VERSION 2.8)\n";
  output_ += "include_directories(";
  output_ += root;
  output_ += ")";
  output_ += "set(CMAKE_C_FLAGS \"${CMAKE_C_FLAGS} -std=c11 -pthread\")\n";
  output_ += "set(CMAKE_CXX_FLAGS \"${CMAKE_CXX_FLAGS} -std=c++11 -pthread")\n";
  output_ += "set(CMAKE_EXE_LINKER_FLAGS \"${CMAKE_EXE_LINKER_FLAGS} -std=c++11 -pthread\")\n";
  output_ += "set(CMAKE_C_FLAGS \"${CMAKE_C_FLAGS} -Wall\")\n";
  output_ += "set(CMAKE_CXX_FLAGS \"${CMAKE_CXX_FLAGS} -Wall\")\n";

}
bool ACBuilder::gen(void)
{
  LOG_INFO(output_);
  return true;
}
