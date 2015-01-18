//
// main.cpp
//

#include <iostream>
#include <string>
#include <boost/asio.hpp>
using namespace std;
extern int http_main(const string &ip,const string &port,const string &root);

int main(int argc, char* argv[])
{
  http_main("127.0.0.1","4447","./");
  return 0;
}
