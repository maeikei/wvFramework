#include "ACBuilder.hpp"
using namespace wator::ac;
#include "debug.h"

#include <list>
#include <fstream>
using namespace std;

#include <boost/algorithm/string.hpp>


const static string constStrCMakeTemplate = 
"project(#{name})\n"
"cmake_minimum_required(VERSION 2.8)\n"
"include_directories(#{root})\n"
"set(CMAKE_C_FLAGS \"${CMAKE_C_FLAGS} -std=c11 -pthread\")\n"
"set(CMAKE_CXX_FLAGS \"${CMAKE_CXX_FLAGS} -std=c++11 -pthread\")\n"
"set(CMAKE_EXE_LINKER_FLAGS \"${CMAKE_EXE_LINKER_FLAGS} -std=c++11 -pthread\")\n"
"set(CMAKE_C_FLAGS \"${CMAKE_C_FLAGS} -Wall\")\n"
"set(CMAKE_CXX_FLAGS \"${CMAKE_CXX_FLAGS} -Wall\")\n"
"#file(GLOB orignal_SRC\n"
"#    app/*.hpp\n"
"#    app/*.cpp\n"
"#    app/Http/*.hpp\n"
"#    app/Http/*.cpp\n"
"#    app/Http/Controllers/*.hpp\n"
"#    app/Http/Controllers/*.cpp\n"
"#    config/*.hpp\n"
"#    config/*.cpp\n"
"#)\n"
"file(GLOB ac_SRC\n"
"    cache/build/src/*.hpp\n"
"    cache/build/src/*.cpp\n"
")\n"
"#message(${orignal_SRC})\n"
"message(${ac_SRC})\n"
"#add_library(#{name} SHARED ${orignal_SRC} ${ac_SRC})\n"
"add_library(#{name} SHARED ${ac_SRC})\n"
"install(TARGETS #{name} DESTINATION lib)\n"
"\n"
;



const static string constStrBuildCmdTemplate =
"all:\n"
"\t mkdir -p #{root}/cache/build/src\n"
"\t mkdir -p #{root}/cache/build/objects\n"
"\t cd #{root}/cache/build/objects && cmake -DCMAKE_INSTALL_PREFIX=#{root}/runtime/ #{root} \n"
"\t cd #{root}/cache/build/objects && make install\n"
"clean:\n"
"\n"
;



ACBuilder::ACBuilder(const fs::path &root)
:root_(root)
,cmake_(constStrCMakeTemplate)
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
  try
  {
    {
      ofstream of;
      of.open(root_.string() + "/CMakeLists.txt",fstream::out);
      of << cmake_;
      of.close();
    }
    {
      ofstream of;
      of.open(root_.string() + "/build.mk",fstream::out);
      of << buildCmd_;
      of.close();
    }
  }
  catch(const exception & e)
  {
    LOG_FATAL(e.what());
  }
  catch(ifstream::failure& e)
  {
    LOG_FATAL(e.what());
  }
  
  return true;
}
