
/* Standard libraries */
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <regex>
#include <iostream>
#include <fstream>

/* source of test functions */
#include "../../inc/functions.hpp"

/* Third party libraries */
#include "../../inc/json.hpp"
/* Third party filesystem library */
#if defined(__cplusplus) && __cplusplus >= 201703L && defined(__has_include) && __has_include(<filesystem>)
#include <filesystem>
namespace fs = std::filesystem;
#else
#include "../../inc/filesystem.hpp"
namespace fs = ghc::filesystem;
#endif

namespace tests{

  void wait();

  void getFileList();

  void move();

  /**********************************************************
    Function gen_random_number
    @arg =>
      (int) max value
    @return => (int) random number between 0 and the max value
  ********************************************************/
  inline int get_random_int(int max){
    srand(static_cast<unsigned int>(std::time(nullptr)));
    return (rand() % ++max);
  }

  /**********************************************************
    Function gen_random_string
    @arg =>
      (int) length of the string to be generated
    @return => (std::string) random string
  ********************************************************/
  inline std::string gen_random_string(const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string s;

    srand(static_cast<unsigned int>(std::time(nullptr)));
    for (int i = 0; i < len; ++i) {
        s.push_back( alphanum[rand() % (sizeof(alphanum) - 1)] );
    }

    return s;
}

}
