#include <string>
#include <list>
using namespace std;
#include "debug.h"
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;

static list<fs::path> gAllControllers;
fs::path gBaseController;

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
      if("Controller.hpp" == entry.path().leaf().string())
      {
        gBaseController = entry.path();
      }
      else
      {
        gAllControllers.push_back(entry.path());
      }
    }
  }
  /// dump info
  LOG_INFO(gBaseController);
  for(auto &ctrl: gAllControllers)
  {
    LOG_INFO(ctrl);
  }
}
