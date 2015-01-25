#include "dispatch.hpp"
using namespace WatorVapor;
#include "reply.hpp"
#include "request.hpp"
using namespace http::server;
#include "debug.h"

Dispatcher::Dispatcher(const http::server::request &req,http::server::reply& rep)
:req_(req)
,rep_(rep)
{
  LOG_DEBUG(req_.method);
  LOG_DEBUG(req_.uri);
  LOG_DEBUG(req_.http_version_major);
  LOG_DEBUG(req_.http_version_minor);
  for(auto head :req_.headers)
  {
    LOG_DEBUG(head.name);
    LOG_DEBUG(head.value);
  }
}
bool Dispatcher::run(void)
{
  return true;
}
 
