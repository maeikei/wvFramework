#include "dispatch.hpp"
using namespace WatorVapor;
#include "reply.hpp"
#include "request.hpp"
using namespace http::server;
#include "debug.h"

Dispatcher::Dispatcher(const http::server::request &req,http::server::reply& rep)
:_req(req)
,_rep(rep)
{
  
}
bool Dispatcher::run(void)
{
  
}
 
