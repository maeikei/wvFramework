#ifndef __AUTO_COMPELETE_CONTROLLER_HPP__
#define __AUTO_COMPELETE_CONTROLLER_HPP__
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;
#include <string>

namespace wator {
namespace ac {
  class ACController
  {
    public:
      ACController(const fs::path &p,const std::string &root);
    private:
      ACController();
  };
} // ac
} // wator

#endif //__AUTO_COMPELETE_CONTROLLER_HPP__
