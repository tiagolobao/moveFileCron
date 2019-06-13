
#include "unit_tests.hpp"

void tests::wait(){
  int testValue = get_random_int(5);
  std::cout << "The test value is: " << testValue << std::endl;
  mvc::wait(testValue);
  std::cout << "Done!" << std::endl;
}
