
#include "../inc/functions.hpp"

void mvc::wait(int t){

    time_t startTime,nowTime;
    double seconds;

    time(&startTime);

    do{
      time(&nowTime);
      seconds = difftime(nowTime,startTime);
    }while(seconds < (double) t);

}
