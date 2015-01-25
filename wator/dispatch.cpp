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
  
}
bool Dispatcher::run(void)
{
  
}
 
