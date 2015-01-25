#ifndef __DISPATCH_HPP__
#define __DISPATCH_HPP__


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
      Dispatcher(http::server::request &req,http::server::reply& rep);
      bool run(void);
    private:
      http::server::request &req_;
      http::server::reply& rep_;
  };
} // namespace WatorVapor
#endif// __DISPATCH_HPP__
