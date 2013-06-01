//            Copyright (c) Glyn Matthews 2010.
// Copyright 2012 Google, Inc.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

//[ hello_world_client_main
/*`
 This is a part of the 'Hello World' example.  We create a client
 object and make a single HTTP request.  If we use make this request
 to the `hello_world_server`, then the output is simply "Hello,
 World!".
 */
#include <network/protocol/http/client.hpp>
#include <iostream>

namespace http = network::http;

int main(int argc, char* argv[]) {
    
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " url" << std::endl;
        return 1;
    }
    
    try {
        /*<< Creates the client. >>*/
        http::client client;
        /*<< Creates a request using a URI supplied on the command
         line. >>*/
        http::client::request request(argv[1]);
#if 0
        request.set_method("GET");
        std::string reqqbody;
        request.get_body(reqqbody);
        std::cout << "reqqbody=<"<< reqqbody  << ">" << std::endl;

        request.get_headers( [](std::string const&name, std::string const&value)
                            {
                                std::cout << "name=<"<< name <<">value=<"<< value << ">" << std::endl;
                            }
                            );
#endif
        /*<< Gets a response from the HTTP server. >>*/
        http::client::response response = client.get(request);
        /*<< Prints the response headers to the console. >>*/
#if 0
        auto h = headers(response);
        std::multimap<std::string, std::string> hmap = h;
        for (auto const & pair :hmap ) {
            std::cout << "pair.first=<"<< pair.first <<">pair.second=<"<< pair.second << ">" << std::endl;
        }
#endif
        /*<< Prints the response body to the console. >>*/
        std::cout << body(response) << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
//]
