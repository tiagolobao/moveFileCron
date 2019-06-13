#include <iostream>
#include "units/unit_tests.hpp"

int main(){

  std::cout << "Starting tests..." << std::endl;

  std::cout << std::endl << "mvc::wait() function test" << std::endl;
  tests::wait();

  std::cout << std::endl << "mvc::move() function test" << std::endl;
  tests::move();

  std::cout << std::endl << "mvc::getFileList() function test" << std::endl;
  tests::getFileList();

  std::cout << std::endl << " TEST DONE!" << std::endl;
  return 0;
}
