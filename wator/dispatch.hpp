#ifndef __DISPATCH_HPP__
#define __DISPATCH_HPP__
#include <string>
using namespace std;

namespace http {
namespace server {
struct reply;
struct request;
} // namespace server
} // namespace http
namespace WatorVapor
{
  class Dispatcher
  {
    public:
      Dispatcher(const http::server::request &req,http::server::reply& rep);
      bool run(void);
    private:
      bool url_decode(const std::string& in, std::string& out);
    private:
      const http::server::request &req_;
      http::server::reply& rep_;
  };
} // namespace WatorVapor
#endif// __DISPATCH_HPP__
