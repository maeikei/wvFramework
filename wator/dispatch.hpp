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
      Dispatcher(request &req,reply& rep);
    private:
      request &req_;
      reply& rep_;
  };
} // namespace WatorVapor
#endif// __DISPATCH_HPP__
