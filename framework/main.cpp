//main.cpp
/*
 */
#include <boost/network/protocol/http/server.hpp>
#include <iostream>


namespace http = boost::network::http;


/*<< Defines the server. >>*/
struct WatorVaporEntry;
typedef http::server<WatorVaporEntry> server;

/*<< Defines the request handler.  It's a class that defines two
 functions, `operator()` and `log()` >>*/
struct WatorVaporEntry
{
    /*<< This is the function that handles the incoming request. >>*/
    void operator() (server::request const &request,server::response &response)
    {
        server::string_type ip = source(request);
        unsigned int port = request.source_port;
        server::string_type method = request.method;
        server::string_type dest = request.destination;
        std::ostringstream data;
        data << "Hello, " << ip << ':' << method << ':'<< port << '!' << dest;
        response = server::response::stock_reply(server::response::ok, data.str());
    }
    void log(...)
    {
        // do nothing
    }
};


int main(int argc, char * argv[]) {
    
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " port" << std::endl;
        return 1;
    }
    try
    {
        /*<< Creates the request handler. >>*/
        WatorVaporEntry handler;
        /*<< Creates the server. >>*/
        server::options options(handler);
        server server_(options.address("0.0.0.0").port(argv[1]));
        /*<< Runs the server. >>*/
        server_.run();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
//]
