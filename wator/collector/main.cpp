#include <string>
#include <list>
using namespace std;
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;

#include "ACController.hpp"
#include "ACBuilder.hpp"
using namespace wator::ac;
#include "debug.h"


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
  ACBuilder builder(root);
  if(false == builder.gen())
  {
    return;
  }
  /// all controller
  LOG_INFO(gBaseController);
  for(auto &ctrl: gAllControllers)
  {
    LOG_INFO(ctrl);
    ACController acCtrl(ctrl,root);
    if(false == acCtrl.gen())
    {
      return;
    }
  }
  /// all model
  LOG_INFO(gBaseModel);
  for(auto &model: gAllModels)
  {
    LOG_INFO(model);
    ACController acCtrl(ctrl,root);
    if(false == acCtrl.gen())
    {
      return;
    }
  }
}
