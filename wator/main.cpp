//
// main.cpp
//

#include <iostream>
#include <string>
using namespace std;
#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>
namespace fs = boost::filesystem;
namespace po = boost::program_options;

#include "debug.h"

extern void http_main(const string &ip,const string &port,const string &root);
extern void collector_main(const fs::path &root);


int main(int argc, char* argv[])
{
  core::get()->set_filter(trivial::severity >= trivial::trace);
  
  po::options_description opt("wator help");
  opt.add_options()
  ("help,h", "show help")
  ("server,s", "start http server")
  ;
  po::variables_map vm;
  try
  {
    po::store(po::parse_command_line(argc, argv, opt), vm);
  } 
  catch(const po::error_with_option_name& e)
  {
      LOG_FATAL( e.what());
      return 1;
  }
  po::notify(vm);
 
  if (vm.count("help"))
  {
    LOG_FATAL(opt);
    return 1;
  }
  
  fs::path pwd_full_path( fs::current_path() );
  LOG_INFO(pwd_full_path);
  collector_main(pwd_full_path;

  if (vm.count("server"))
  {
    http_main("0.0.0.0","4447",pwd_full_path.string() + "/public");
  } 
  return 0;
}
