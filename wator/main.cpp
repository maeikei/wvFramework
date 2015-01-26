//
// main.cpp
//

#include <iostream>
#include <string>
using namespace std;
#include <boost/filesystem.hpp>
#include "debug.h"

extern void http_main(const string &ip,const string &port,const string &root);
extern void collector_main(const string &root);


int main(int argc, char* argv[])
{
  core::get()->set_filter(trivial::severity >= trivial::trace);
  
  boost::filesystem::path pwd_full_path( boost::filesystem::current_path() );
  LOG_INFO(pwd_full_path);
  collector_main(pwd_full_path.string());

  http_main("0.0.0.0","4447",pwd_full_path.string() + "/public");
  return 0;
}
