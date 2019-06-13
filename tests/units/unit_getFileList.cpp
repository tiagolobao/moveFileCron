
#include "unit_tests.hpp"


/***************************
  Response checker
****************************/
void checkResponse(
  std::vector<std::string> expected,
  std::vector<std::string> response
){
  try{
    if( expected != response )
      throw std::runtime_error(" Error on getFileList function!");
  } catch( std::runtime_error & e ){
    std::cout << e.what() << std::endl;
  }
}


void tests::getFileList(){

  std::string regex = "_file";
  std::vector<std::string> expected, matches;

  /************************
    Creating directory
  ************************/
  std::string source = "temp/";
  if( !fs::exists( source ) ){
    fs::create_directory( source ); //Create temp directory
  }

  /************************
    Creating two files with diferent write dates
  ************************/
  std::string filename;
  std::ofstream ofs;
  fs::path p;

  /* Create old file */
  filename = "oldest_file";
  p = source + filename;
  ofs.open (p, std::ofstream::out | std::ofstream::app);
  ofs << "this is some text in the new file\n";
  ofs.close();

  /* Create new file */
  filename = "newest_file";
  p = source + filename;
  ofs.open (p, std::ofstream::out | std::ofstream::app);
  ofs << "this is some text in the new file\n";
  ofs.close();
  fs::file_time_type ftime = fs::last_write_time( p );
  fs::last_write_time( p, ftime + std::chrono::hours(1) ); // move file write time to the future

  /* Create garbage file */
  filename = gen_random_string(5);
  p = source + filename;
  ofs.open (p, std::ofstream::out | std::ofstream::app);
  ofs << "this is some text in the new file\n";
  ofs.close();

  /****************************
    Call getFileList function (newest mode operation)
    And check response
  *****************************/
  matches = mvc::getFileList(
    regex,
    source,
    mvc::createFileList_option( "newest" )
  );

  expected = { "newest_file" };
  checkResponse(expected, matches);

  /****************************
    Call getFileList function (oldest mode operation)
    And check response
  *****************************/
  matches = mvc::getFileList(
    regex,
    source,
    mvc::createFileList_option( "oldest" )
  );
  expected = { "oldest_file" };
  checkResponse(expected, matches);

  /****************************
    Call getFileList function (all mode operation)
    And check response
  *****************************/
  matches = mvc::getFileList(
    regex,
    source,
    mvc::createFileList_option( "all" )
  );
  // expected = { "oldest_file", "newest_file" };
  expected = { "newest_file", "oldest_file" };
  checkResponse(expected, matches);

  fs::remove_all( source );
  fs::create_directory( source );
  std::cout << "Done!" << std::endl;

}
