#include "ACBuilder.hpp"
using namespace wator::ac;
#include "debug.h"

#include <list>
#include <boost/algorithm/string.hpp>

using namespace std;

const static string constStrCMakeTemplate = "\n"
"project(#{name})\n"
"cmake_minimum_required(VERSION 2.8)\n"
"include_directories(#{root})\n"
"set(CMAKE_C_FLAGS \"${CMAKE_C_FLAGS} -std=c11 -pthread\")\n"
"set(CMAKE_CXX_FLAGS \"${CMAKE_CXX_FLAGS} -std=c++11 -pthread\")\n"
"set(CMAKE_EXE_LINKER_FLAGS \"${CMAKE_EXE_LINKER_FLAGS} -std=c++11 -pthread\")\n"
"set(CMAKE_C_FLAGS \"${CMAKE_C_FLAGS} -Wall\")\n"
"set(CMAKE_CXX_FLAGS \"${CMAKE_CXX_FLAGS} -Wall\")\n"
;


const static string constStrBuildCmdTemplate = "\n"
"all:\n"
"\t mkdir -p #{root}/cache/build/objects\n"
"\t cd #{root}/cache/build/objects && cmake -DCMAKE_INSTALL_PREFIX={root}/cache/exec/\n"
"\t cd #{root}/cache/build/objects && make install\n"
"clean:\n"
;



ACBuilder::ACBuilder(const fs::path &root)
:cmake_(constStrCMakeTemplate)
,buildCmd_(constStrBuildCmdTemplate)
{
  cmake_ = boost::algorithm::replace_all_copy(cmake_,"#{name}",root.leaf().string());
  cmake_ = boost::algorithm::replace_all_copy(cmake_,"#{root}",root.string());
  
  
  build_cmd_ = boost::algorithm::replace_all_copy(build_cmd_,"#{root}",root.string());
/*  
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

  build_cmd_ += "all:";
  build_cmd_ += "\t mkdir -p";
  build_cmd_ += "\t cd ";
*/

}
bool ACBuilder::gen(void)
{
  LOG_INFO(cmake_);
  LOG_INFO(buildCmd_);
  return true;
}
