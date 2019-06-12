
#include "../inc/functions.hpp"

/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
void mvc::wait(int t){

    time_t startTime,nowTime;
    double seconds;

    time(&startTime);

    do{
      time(&nowTime);
      seconds = difftime(nowTime,startTime);
    }while(seconds < (double) t);

}

/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
std::vector<std::string> mvc::getFileList(std::string exp, std::string path){

  std::vector<std::string> matches;
  std::smatch m;

  for (const auto & entry : fs::directory_iterator(path)){
    std::string file = entry.path().filename().generic_string();
    std::regex_search(file, m, std::regex(exp));
    if( !m.empty() ){
      matches.push_back( file );
    }
  }

  return matches;
}
