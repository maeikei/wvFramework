#ifndef __AUTO_COMPELETE_MODEL_HPP__
#define __AUTO_COMPELETE_MODEL_HPP__
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;
#include <string>

namespace wator {
namespace ac {
  class ACModel
  {
    public:
      ACModel(const fs::path &p,const std::string &root);
      bool gen(void);
    private:
      ACModel();
  };
} // ac
} // wator

#endif //__AUTO_COMPELETE_MODEL_HPP__
