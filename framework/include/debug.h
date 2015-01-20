#ifndef __DEBUG_H__
#define __DEBUG_H__

#define LOG_TRACE(x) BOOST_LOG_TRIVIAL(trace) << __func__ << " " << __LINE__ << ":" << #x << "=<" << x << ">\n";
#define LOG_DEBUG(x) BOOST_LOG_TRIVIAL(debug) << __func__ << " " << __LINE__ << ":" << #x << "=<" << x << ">\n";
#define LOG_INFO(x) BOOST_LOG_TRIVIAL(info) << __func__ << " " << __LINE__ << ":" << #x << "=<" << x << ">\n";
#define LOG_WARNING(x) BOOST_LOG_TRIVIAL(warning) << __func__ << " " << __LINE__ << ":" << #x << "=<" << x << ">\n";
#define LOG_ERROR(x) BOOST_LOG_TRIVIAL(error) << __func__ << " " << __LINE__ << ":" << #x << "=<" << x << ">\n";
#define LOG_FATAL(x) BOOST_LOG_TRIVIAL(fatal) << __func__ << " " << __LINE__ << ":" << #x << "=<" << x << ">\n";


#endif
