// Copyright 2009 (c) Tarro, Inc.
// Copyright 2009 (c) Dean Michael Berris <dberris@google.com>
// Copyright 2012 Google, Inc.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

//[ hello_world_server_main
/*`
 This is a part of the 'Hello World' example. It's used to
 demonstrate how easy it is to set up an HTTP server.  All we do in
 this example is create a request handler and run the server.
 */

#include <network/protocol/http/server/options.hpp>
#include <network/protocol/http/server.hpp>
#include <iostream>

namespace http = network::http;

/*<< Defines the server. >>*/
struct hello_world;
typedef http::sync_server<hello_world> server;

/*<< Defines the request handler.  It's a class that defines two
 functions, `operator()` and `log()` >>*/
struct hello_world {
    /*<< This is the function that handles the incoming request. >>*/
    void operator()(server::request const& request, server::response& response) {
        //server::string_type ip = source(request);
        //std::ostringstream data;
        //data << "Hello, " << ip << "!";
        //response = server::response::stock_reply(
        //    server::response::ok, data.str());
    }
    /*<< It's necessary to define a log function, but it's ignored in
     this example. >>*/
    void log(...) {
        // do nothing
    }
};

int main(int argc, char* argv[]) {
    
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " address port" << std::endl;
        return 1;
    }
    
    try {
        /*<< Creates the request handler. >>*/
        hello_world handler;
        /*<< Creates the server. >>*/
        http::server_options options;
        server server_(options.address(argv[1]).port(argv[2]), handler);
        /*<< Runs the server. >>*/
        server_.run();
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
//]

