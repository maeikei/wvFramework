//
// request.hpp
// ~~~~~~~~~~~

#ifndef __WATOR_REQUEST_HPP__
#define __WATOR_REQUEST_HPP__

#include <string>
#include <map>

namespace wator {
namespace http {

/// A request received from a client.
struct Request
{
  std::string method;
  std::string uri;
  int http_version_major;
  int http_version_minor;
  std::map<string,string> headers;
};

} // namespace http
} // namespace wator

#endif // __WATOR_REQUEST_HPP__
