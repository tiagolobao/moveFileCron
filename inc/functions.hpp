
#ifndef MVC_FUNCTIONS
#define MVC_FUNCTIONS

#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <regex>

namespace mvc{

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
    @return => (std::vector<string>) List of files
     This function searchs for files in a directory that matches a regex
  ********************************************************/
  std::vector<std::string> getFileList(std::string exp, std::string path);

  /**********************************************************
    Function getFileList
    @arg =>
      (string) path to source file to transfer
      (string) path to destination
    @return => void
     This function moves a file from one directory to another
  ********************************************************/
  void move(std::string source, std::string destination);
}

#endif
