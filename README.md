

# moveFileCron
IFE Coding Challange.
(P.S. MVC is not Model-View-Controller in this context)

Transfer files between directories based on the filename. Checked with Regex and transferred periodically.

## Usage

* Compile
```bash
cd path/to/source #change directory
cmake . #create make file
make #compile
```
* Create configuration file (config.json). You can also copy the config.example.json file. The only requirement is that <b> the filename must be config.json </b>
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
## Configuration

### Mode (std::string)
|  Value   |   Behavior                   |
|   ---    |     ---                      |
|  "all"   | Move all files that matches  |
| "newest" | Move only the newest file that mathces  |
| "oldest" | Move only the oldest file that mathces  |

### Time (int)

Integer value in seconds. Delay for each move operation

### Regex (std::string)

Any valid regex expression for standard C++ library std::regex

### Directory (Json)

* From (std::string) => Source directory.
* To (std::string)  => Destination directory

## Third party software
* [JSON for Modern C++](https://github.com/nlohmann/json)
* [An implementation of C++17 std::filesystem for C++11 /C++14/C++17 on Windows, macOS and Linux. ](https://github.com/gulrak/filesystem)
