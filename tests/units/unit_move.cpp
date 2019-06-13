
#include "unit_tests.hpp"

void tests::move(){

  /************************
    Creating files to move
  ************************/
  if( !fs::exists( "temp" ) ){
    fs::create_directory( "temp" ); //Create temp directory
  }

  std::string destination = "temp/destinationPath/";
  if( !fs::exists( destination ) ){
    fs::create_directory( destination ); //Create destination directory
  }

  std::string source = "temp/sourcePath/";
  if( !fs::exists( source ) ){
    fs::create_directory( source ); //Create source directory
  }

  //Create file in source with a random filename
  std::string filename = tests::gen_random_string(5);
  std::cout << filename << std::endl;
  if( !fs::exists( source + filename ) ){
    std::ofstream ofs( fs::path( source + filename ) );
    ofs << "this is some text in the new file\n";
    ofs.close();
  }

  /***************************
    Call function
  ****************************/
  mvc::move(
    source,
    destination,
    filename
  );

  /***************************
    Check if files where moved
  ****************************/
  if( fs::exists( destination + filename ) ){
    fs::remove( destination + filename );
    std::cout << "Done!" << std::endl;
  }
  else{
    std::cout << "Error on move function!" << std::endl;
  }

}
