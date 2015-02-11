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
      ACBuilder(const fs::path &root);
      bool gen(void);
    private:
      ACBuilder();
    private:
      std::string cmake_;
  };
} // ac
} // wator

#endif //__AUTO_COMPELETE_BUILDER_HPP__
