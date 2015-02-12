#ifndef __AUTO_COMPELETE_CONFIG_HPP__
#define __AUTO_COMPELETE_CONFIG_HPP__
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;
#include <string>

namespace wator {
namespace ac {
  class ACConfig
  {
    public:
      ACConfig(const fs::path &root);
      bool gen(void);
    private:
      ACConfig();
    private:
      fs::path root_;
      std::string cpp_;
  };
} // ac
} // wator

#endif //__AUTO_COMPELETE_CONFIG_HPP__

