#ifndef __AUTO_COMPELETE_BUILDER_HPP__
#define __AUTO_COMPELETE_BUILDER_HPP__
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;
#include <string>

namespace wator {
namespace ac {
  class ACBuilder
  {
    public:
      ACBuilder(const fs::path &p,const std::string &root);
    private:
      ACBuilder();
  };
} // ac
} // wator

#endif //__AUTO_COMPELETE_BUILDER_HPP__
