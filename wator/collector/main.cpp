#include <string>
using namespace std;
#include "debug.h"
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;

void collector_main(const string &root)
{
  LOG_INFO(root);
  fs::path controller(root);
  controller += "/app/Http/Controllers";
  LOG_INFO(controller);
  
}
