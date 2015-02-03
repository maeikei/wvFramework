#include <string>
#include <list>
using namespace std;
#include "debug.h"
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;

list<fs::path> gAllControllers;
fs::path gBaseController;

list<fs::path> gAllModels;
fs::path gBaseModel;


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

  fs::path model(root);
  model += "/app/Models";
  LOG_INFO(model);
  if(fs::is_directory(model))
  {
    for(auto& entry : boost::make_iterator_range(fs::directory_iterator(model), {}))
    {
      if("Model.hpp" == entry.path().leaf().string())
      {
        gBaseModel = entry.path();
      }
      else
      {
        gAllModels.push_back(entry.path());
      }
    }
  }
  /// dump info
  LOG_INFO(gBaseModel);
  for(auto &mdls: gAllModels)
  {
    LOG_INFO(mdls);
  }
}
