//
// app.hpp
// ~~~~~~~~~~~

#ifndef __WATOR_APP_HPP__
#define __WATOR_APP_HPP__

namespace wator {
namespace http {

struct app
{
	static const bool debug;
	static const string url;
	static const string timezone;
	static const string locale;
	static const string fallback_locale;
	static const string key;
	static const string cipher;
	static const string log;	
};
} // namespace http
} // namespace wator

#endif // __WATOR_APP_HPP__
