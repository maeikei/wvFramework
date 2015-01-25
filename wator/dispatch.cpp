#include "dispatch.hpp"
using namespace wator;
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
// Decode url to path.
  std::string request_path;
  if (!url_decode(req_.uri, request_path))
  {
    return false;
  }
  LOG_DEBUG(request_path);
  return true;
}
 
bool Dispatcher::url_decode(const std::string& in, std::string& out)
{
  out.clear();
  out.reserve(in.size());
  for (std::size_t i = 0; i < in.size(); ++i)
  {
    if (in[i] == '%')
    {
      if (i + 3 <= in.size())
      {
        int value = 0;
        std::istringstream is(in.substr(i + 1, 2));
        if (is >> std::hex >> value)
        {
          out += static_cast<char>(value);
          i += 2;
        }
        else
        {
          return false;
        }
      }
      else
      {
        return false;
      }
    }
    else if (in[i] == '+')
    {
      out += ' ';
    }
    else
    {
      out += in[i];
    }
  }
  return true;
} 
 
