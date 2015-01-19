//
// main.cpp
//

#include <iostream>
#include <string>
#include <boost/filesystem.hpp>
using namespace std;
extern int http_main(const string &ip,const string &port,const string &root);

int main(int argc, char* argv[])
{
  boost::filesystem::path full_path( boost::filesystem::current_path() );
  std::cout << "Current path is : " << full_path << std::endl;
  http_main("0.0.0.0","4447",full_path.strint());
  return 0;
}
