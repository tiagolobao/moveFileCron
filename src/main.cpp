/* Standard libraries */
#include <iostream>

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

    std::cout << "Step done" << std::endl;
  }

  return 0;
}
