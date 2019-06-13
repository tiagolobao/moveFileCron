
/* Standard libraries */
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <regex>
#include <iostream>

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

}
