
# moveFileCron
IFE Coding Challange.
(P.S. MVC is not Model-View-Controller)

Transfer files between directories based on the filename. Checked with Regex and transferred periodically.

### Usage

* Compile
```bash
cd move_to_path
cmake . #create make file
make #compile
```
* Change configuration file (config.json)
```json
{
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
