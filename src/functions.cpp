
#include "../inc/functions.hpp"

/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
void mvc::wait(int t){

  std::this_thread::sleep_for (std::chrono::seconds(t));

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
std::vector<std::string> mvc::getFileList(std::string exp, std::string path, int option){

  if( option == mvc::fileList_options::all )
    return mvc::getFileList(exp, path);

  std::vector<std::string> matches = {};
  std::smatch m;
  fs::file_time_type lastTime;
  if( option == mvc::fileList_options::newest )
    lastTime = fs::file_time_type::min();
  else if( option == mvc::fileList_options::oldest )
    lastTime = fs::file_time_type::max();

  for ( const auto & entry : fs::directory_iterator(path) ){
    std::string file = entry.path().filename().generic_string();
    std::regex_search( file, m, std::regex(exp) );

    if( !m.empty() ){
      fs::file_time_type fileTime = fs::last_write_time(entry.path());
      bool chooseFlag = false;
      if( option == mvc::fileList_options::newest ){
        if( fileTime > lastTime ) chooseFlag = true;
      }
      else if( option == mvc::fileList_options::oldest ){
        if( fileTime < lastTime ) chooseFlag = true;
      }
      if(chooseFlag){ //Change choosen file
        lastTime = fileTime;
        matches = {file};
      }
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
    fs::copy_file(oldFilePath, newFilePath, fs::copy_options::overwrite_existing);
    fs::remove(oldFilePath);
  } catch(fs::filesystem_error& e) {
    std::cout << "Could not move " << oldFilePath << " => " << e.what() << '\n';
  }

  return;
}

/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
bool mvc::verifyConfigVar(nlohmann::json j){

  try{

    /* MODE ARGUMENT */
    if( !j["mode"].is_string() )
      throw std::invalid_argument( "Invalid or inexistent mode argument" );
    /* REGEX ARGUMENT */
    if( !j["regex"].is_string() )
      throw std::invalid_argument( "Invalid or inexistent regex argument" );

    /* TIME ARGUMENT */
    if( !j["time"].is_number() ){
      throw std::invalid_argument( "Invalid or inexistent time argument" );
    }
    else{
      int test = j["time"];
      if( j["time"] != test )
        throw std::invalid_argument( "Time is not an integer" );
    }

    /* DIRECTORY ARGUMENT */
    if( !j["directory"].is_object() ){
      throw std::invalid_argument( "Invalid or inexistent directory argument" );
    }
    else{
      if( !j["directory"]["from"].is_string() )
        throw std::invalid_argument( "Invalid or inexistent source directory argument" );
      if( !fs::exists( (std::string) j["directory"]["from"] ) )
        throw std::invalid_argument( "source directory does not exists" );
      if( !j["directory"]["to"].is_string() )
        throw std::invalid_argument( "Invalid or inexistent destination directory argument" );
      if( !fs::exists( (std::string) j["directory"]["to"] ) )
        throw std::invalid_argument( "destination directory does not exists" );
    }

  } catch ( const std::invalid_argument& e ){
    std::cout
      << "Config file error => "
      << e.what()
      << std::endl;
    return false;
  }

  return true;
}
