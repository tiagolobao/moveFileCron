
#ifndef MVC_FUNCTIONS
#define MVC_FUNCTIONS

/* Standard libraries */
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <regex>
#include <iostream>

/* Third party libraries */
#include "json.hpp"
/* Third party filesystem library */
#if defined(__cplusplus) && __cplusplus >= 201703L && defined(__has_include) && __has_include(<filesystem>)
#include <filesystem>
namespace fs = std::filesystem;
#else
#include "filesystem.hpp"
namespace fs = ghc::filesystem;
#endif

namespace mvc{

  namespace fileList_options{
    enum{
      all, //Returns all files that mathces
      newest, //Returns only the newest one
      oldest //Returns only the oldest one
    };
  }

  /**********************************************************
    Function wait
    @arg =>
      (int) time value in seconds
    @return => void
     This function is similar to sleep and makes the software wait during a
     specific time
  ********************************************************/
  void wait(int time);

  /**********************************************************
    Function getFileList
    @arg =>
      (string) regular expression
      (string) directory to search
      (boolean) option to return only most recent [optional]
    @return => (std::vector<string>) List of files
     This function searchs for files in a directory that matches a regex
  ********************************************************/
  std::vector<std::string> getFileList(std::string exp, std::string path);
  std::vector<std::string> getFileList(std::string exp, std::string path, int option);

  /**********************************************************
    Function createFileList_option()
    @arg =>
      (string) verbose configuration
    @return => (int) respective operation mode integer value
    This function returns the rigth value ot a given config string.
    Used to parse a config file.
  ********************************************************/
  int createFileList_option(std::string mode);

  /**********************************************************
    Function getFileList
    @arg =>
      (string) path to source file to transfer
      (string) path to destination
      (string) filename to transfer
    @return => void
     This function moves a file from one directory to another
  ********************************************************/
  void move(std::string source, std::string destination, std::string fileName);

  /**********************************************************
    Function verifyConfigVar
    @arg =>
      (nlohmann::json) parsed config file
    @return => (bool) true if was succesful
     Verify if all config parameters is given in the right types. Makes easier
     to fix errors.
  ********************************************************/
  bool verifyConfigVar(nlohmann::json j);
}

#endif
