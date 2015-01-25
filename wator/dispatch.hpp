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
      Dispatcher(const wator::server::request &req,wator::server::reply& rep);
      bool run(void);
    private:
      bool url_decode(const std::string& in, std::string& out);
    private:
      const wator::server::request &req_;
      wator::server::reply& rep_;
  };
} // namespace wator
#endif// __DISPATCH_HPP__
