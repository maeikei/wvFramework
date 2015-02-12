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
"file(GLOB orignal_SRC\n"
"    \"app/*.hpp\"\n"
"    \"app/*.cpp\"\n"
"    \"app/Http/*.hpp\"\n"
"    \"app/Http/*.cpp\"\n"
"    \"app/Http/Controllers/*.hpp\"\n"
"    \"app/Http/Controllers/*.cpp\"\n"
"    \"config/*.hpp\"\n"
"    \"config/*.cpp\"\n"
")\n"
"file(GLOB ac_SRC\n"
"    \"cache/build/ac/*.hpp\"\n"
"    \"cache/build/ac/*.cpp\"\n"
")\n"
"add_library(#{name} SHARED ${orignal_SRC} ${ac_SRC})"
;


const static string constStrBuildCmdTemplate = "\n"
"all:\n"
"\t mkdir -p #{root}/cache/build/objects\n"
"\t cd #{root}/cache/build/objects && cmake -DCMAKE_INSTALL_PREFIX=#{root}/runtime/\n"
"\t cd #{root}/cache/build/objects && make install\n"
"clean:\n"
;



ACBuilder::ACBuilder(const fs::path &root)
:cmake_(constStrCMakeTemplate)
,buildCmd_(constStrBuildCmdTemplate)
{
  cmake_ = boost::algorithm::replace_all_copy(cmake_,"#{name}",root.leaf().string());
  cmake_ = boost::algorithm::replace_all_copy(cmake_,"#{root}",root.string());
  
  
  buildCmd_ = boost::algorithm::replace_all_copy(buildCmd_,"#{root}",root.string());

}
bool ACBuilder::gen(void)
{
  LOG_INFO(cmake_);
  LOG_INFO(buildCmd_);
  return true;
}
