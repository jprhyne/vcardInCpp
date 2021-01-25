# vcardInCpp
This program provides a command line interface to read in a vCard file, and either create a new xml file or appends the data to an existing xml file used
by the purple plugin List Handler (Currently have to create a new xml. Further functionality is in progress)
# Requirements
```
g++
make
```
# Credits
I also used pugixml source file by Zeux found at: https://github.com/zeux/pugixml
# Compilation
## \*NIX-like
```
make && src/vcardToXML
```
If you want the source file on your PATH, you can either add `/path/to/vcardInCpp/src` to your PATH or run
`make install` to copy the source file to `/usr/bin`.

## Windows
While I did not develop this with the intent of being used on a windows system, if you need to run this under windows, follow the steps outlined here to set up Visual Studio
or to compile from the command line. The header files are in the `include` folder.

Compilation: https://docs.microsoft.com/en-us/cpp/build/walkthrough-compiling-a-native-cpp-program-on-the-command-line?view=msvc-160

Visual Studio: https://visualstudio.microsoft.com/vs/features/cplusplus/
# TODO
Find out why there is a memory leak for `./vcardToXML` with valid vcf file (7 nodes)
Add support for existing xml files
