#include <string>
using namespace std;
#include "debug.h"
#include <boost/filesystem.hpp>

void collector_main(const string &root)
{
  LOG_INFO(root);
  boost::filesystem::controller(root);
  LOG_INFO(controller);
  
}
