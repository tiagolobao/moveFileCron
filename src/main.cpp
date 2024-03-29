/* Standard libraries */
#include <iostream>
#include <string>
#include <vector>

/* Implemented headers */
#include "../inc/functions.hpp"

/* Third party libraries */
#include "../inc/json.hpp"

int main(){

  /* Load config file */
  std::cout << "Loading config file..." << std::endl;
  std::ifstream ifile("config.json");
  nlohmann::json config;
  ifile >> config;

  /* Exceptions treatment */
  if( !mvc::verifyConfigVar(config) ) exit(1);

  std::cout << "Time set to " << config["time"] << " seconds" << std::endl;

  /* operation mode selection */
  int mode = mvc::createFileList_option( (std::string) config["mode"] );
  std::cout << "Operation mode set to: " << config["mode"] << std::endl;

  /* Only finish when process is killed */
  while(1){

    /* Timer */
    mvc::wait(config["time"]);

    /* Get list of files in source directory */
    std::vector<std::string> matches = mvc::getFileList(
      config["regex"],
      config["directory"]["from"],
      mode
    );

    /* Move each file that matched */
    for(std::string file : matches){
      std::cout << "Matches: " << (std::string) config["directory"]["from"] + file << std::endl;
      mvc::move(
        (std::string) config["directory"]["from"],
        (std::string) config["directory"]["to"],
        file
      );
    }

  }

  return 0;
}
