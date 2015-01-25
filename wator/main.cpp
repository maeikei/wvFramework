//
// main.cpp
//

#include <iostream>
#include <string>
using namespace std;
#include <boost/filesystem.hpp>
#include "debug.h"

extern int http_main(const string &ip,const string &port,const string &root);

int main(int argc, char* argv[])
{
  core::get()->set_filter(trivial::severity >= trivial::info);
  
  boost::filesystem::path pwd_full_path( boost::filesystem::current_path() );
  LOG_INFO(pwd_full_path);
  http_main("0.0.0.0","4447",pwd_full_path.string() + "/public");
  return 0;
}
