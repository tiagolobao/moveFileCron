
#include "unit_tests.hpp"

void tests::wait(){

  /* Generate random wait value */
  int testValue = get_random_int(5);
  std::cout << "The test value is: " << testValue << std::endl;

  time_t before, after;

  try{

    /* Wait */
    time(&before);
    mvc::wait(testValue);
    time(&after);

    /* Calc difference between hours */
    int waitedTime = difftime(after, before);
    if( waitedTime != testValue )
      throw std::runtime_error(std::to_string(waitedTime));

  } catch( std::runtime_error & e ){
  std::cout << "Error on wait => Time: " << e.what() << std::endl;
  }

  std::cout << "Done!" << std::endl;
}
