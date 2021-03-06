#include "ACConfig.hpp"
using namespace wator::ac;
#include <list>
#include <fstream>
using namespace std;

#include "debug.h"

const static string constStrConfigCppTemplate = 
"/*Auto generated file DO not modify!!!! */\n"
"#include <string>\n"
"using namespace std;\n"
"#include <app.hpp>\n"
"using namespace wator::http;\n"
"#include <config/app.cpp>\n"
"\n"
;


ACConfig::ACConfig(const fs::path &root)
:root_(root)
,cpp_(constStrConfigCppTemplate)
{
  
}
bool ACConfig::gen(void)
{
  LOG_INFO(cpp_);
  try
  {
    {
      ofstream of;
      LOG_INFO(root_.string() + "/cache/build/src/config.cpp");
      of.open(root_.string() + "/cache/build/src/config.cpp",fstream::out);
      of << cpp_;
      of.close();
      LOG_INFO(root_.string() + "/cache/build/src/config.cpp");
    }
  }
  catch(exception & e)
  {
    LOG_FATAL(e.what());
  }
  catch(ifstream::failure& e)
  {
    LOG_FATAL(e.what());
  }
  return true;
}
