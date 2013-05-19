// Copyright 2009 (c) Tarro, Inc.
// Copyright 2009-2010 (c) Dean Michael Berris <dberris@google.com>
// Copyright 2012 Google, Inc.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#include <cstdlib>
#include <string>
#include <iostream>

#include <network/utils/thread_pool.hpp>
#include <network/protocol/http/request.hpp>
#include <network/protocol/http/response.hpp>
#include <network/protocol/http/server.hpp>


namespace http = network::http;

struct hello_world;
typedef http::sync_server<hello_world> server;

struct hello_world {
    
    void operator()(http::request const& request, http::response& response) {
    }
    void log(std::string const& data) {
        std::cerr << data << std::endl;
        abort();
    }
};

int main(int argc, char* argv[]) {
    hello_world handler;
    std::string port = "8084";
    if (argc > 1)
        port = argv[1];
    http::server_options options;
    options.address("127.0.0.1").port(port).reuse_address(true);
    server server_(options, handler);
    server_.run();
    return 0;
}

#include "network/protocol/http/server/options.ipp"
//#include "network/protocol/http/server/server.ipp"
#include "network/protocol/http/server/sync_impl.ipp"
