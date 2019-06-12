
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

/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
int mvc::createFileList_option(std::string mode){

  int value = 0;
  try{
    if( mode == "all" )
      value = mvc::fileList_options::all;
    else if( mode == "newest" )
      value = mvc::fileList_options::newest;
    else if( mode == "oldest" )
      value = mvc::fileList_options::oldest;
    else
      throw std::invalid_argument( "Invalid operation mode" );
  } catch ( const std::invalid_argument& e ) {
    std::cout << "Error to create fileList_options => " << e.what() << std::endl;
    exit(1);
  }

  return value;
}

/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
void mvc::move(std::string source, std::string destination, std::string fileName){

  std::string newFilePath = destination + fileName;
  std::string oldFilePath = source + fileName;
  try {
    fs::copy_file(oldFilePath, newFilePath);
    fs::remove(oldFilePath);
  } catch(fs::filesystem_error& e) {
    std::cout << "Could not move " << oldFilePath << " => " << e.what() << '\n';
  }

  return;
}
