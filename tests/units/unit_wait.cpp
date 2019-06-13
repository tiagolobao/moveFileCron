
#include "unit_tests.hpp"

void tests::wait(){
  srand(time(0));
  int testValue = rand() % 6;  // range 0 to 5
  std::cout << "The test value is: " << testValue << std::endl;
  mvc::wait(testValue);
  std::cout << "Done!" << std::endl;
}
