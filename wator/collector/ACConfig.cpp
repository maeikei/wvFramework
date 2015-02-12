#include "ACConfig.hpp"
using namespace wator::ac;
using namespace std;

const static string constStrConfigCppTemplate = 
"/*Auto generated file DO not modify!!!! */\n"
"namespace wator {\n"
"namespace ag {\n"
"#include <config/app.hpp>\n"
"} // ag\n"
"} // wator\n"
"wator::ag::app globalApp;"
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
      of.open(root_.string() + "cache/build/src/config.cpp");
      of << cpp_;
      of.close();
    }
  }
  catch(const exception & e)
  {
    LOG_FATAL(e.what());
  } 
  return true;
}
