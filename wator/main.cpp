//
// main.cpp
//

#include <iostream>
#include <string>
using namespace std;
#include <boost/filesystem.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
using namespace boost::log;
#include "debug.h"

extern int http_main(const string &ip,const string &port,const string &root);

int main(int argc, char* argv[])
{
  core::get()->set_filter(trivial::severity >= trivial::info);
  
  boost::filesystem::path full_path( boost::filesystem::current_path() );
  BOOST_LOG_TRIVIAL(info) << "Current path is : " << full_path;
  http_main("0.0.0.0","4447",full_path.string());
  return 0;
}
