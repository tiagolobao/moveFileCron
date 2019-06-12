
# moveFileCron
IFE Coding Challange.
(P.S. MVC is not Model-View-Controller in this context)

Transfer files between directories based on the filename. Checked with Regex and transferred periodically.

### Usage

* Compile
```bash
cd path/to/source #change directory
cmake . #create make file
make #compile
```
* Change configuration file (config.json)
```javascript
{
  "mode": "all", //Operation mode
  "time": 60, //Timer
  "regex": "cool.*\\.txt", //Regex string to find files
  "directory": {
    "from": "test/temp/destinationPath/", //Destination path
    "to": "test/temp/sourcePath/" //Source path
  }
}
```

* Run
```bash
./mvc
```
### Third party software
* [JSON for Modern C++](https://github.com/nlohmann/json)
* [An implementation of C++17 std::filesystem for C++11 /C++14/C++17 on Windows, macOS and Linux. ](https://github.com/gulrak/filesystem)
