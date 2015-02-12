#include "ACConfig.hpp"
using namespace wator::ac;
#include <list>
#include <fstream>
using namespace std;

#include "debug.h"

const static string constStrConfigCppTemplate = 
"/*Auto generated file DO not modify!!!! */\n"
"namespace wator {\n"
"namespace autogen {\n"
"#include <config/app.hpp>\n"
"} // autogen\n"
"} // wator\n"
"wator::autogen::app globalApp;"
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
