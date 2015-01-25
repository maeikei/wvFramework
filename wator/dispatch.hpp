#ifndef __DISPATCH_HPP__
#define __DISPATCH_HPP__
#include <string>
using namespace std;

namespace wator {
namespace server {
struct reply;
struct request;
} // namespace server
} // namespace wator
namespace wator
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
} // namespace wator
#endif// __DISPATCH_HPP__
