//
// main.cpp
// ~~~~~~~~
//
// Copyright (c) 2003-2014 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include "server.hpp"
using namespace std;
#include "debug.h"

void http_main(const string &ip,const string &port,const string &root)
{
  try
  {
    // Initialise the server.
    LOG_INFO(ip);
    LOG_INFO(port);
    LOG_INFO(root);
    wator::server::server s(ip, port, root);

    // Run the server until stopped.
    s.run();
  }
  catch (std::exception& e)
  {
    std::cerr << "exception: " << e.what() << "\n";
  }

  return;
}
