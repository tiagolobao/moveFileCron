#include <iostream>
#include "units/unit_tests.hpp"

int main(){

  std::cout << "Starting tests..." << std::endl;

  std::cout << "mvc::wait() function test" << std::endl;
  tests::wait();

  std::cout << "mvc::move() function test" << std::endl;
  // tests::move();

  std::cout << "mvc::getFileList() function test" << std::endl;
  // tests::getFileList();

  std::cout << "Done!" << std::endl;
  return 0;
}
