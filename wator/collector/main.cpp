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
  if(fs::is_directory(controller))
  {
    for(auto& entry : boost::make_iterator_range(fs::directory_iterator(controller), {}))
    {
      LOG_INFO(entry);
    }
  }
  
}
