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
  std::cout << "Time set to " << config["time"] << " seconds" << std::endl;

  while(1){
    std::cout << std::endl;

    mvc::wait(config["time"]);

    std::vector<std::string> matches = mvc::getFileList(
      config["regex"],
      config["directory"]["from"]
    );

    for(std::string file : matches){
      std::cout << "Matches: " << file << std::endl;
    }

    std::cout << "Step done" << std::endl;
  }

  return 0;
}
