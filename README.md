# vcardInCpp
This program provides a command line interface to read in a vCard file, and either create a new xml file or appends the data to an existing xml file used
by the purple plugin List Handler
# Requirements
```
g++
make
```
# Credits
I also used pugixml source file by Zeux found at: https://github.com/zeux/pugixml
# Compilation
```
make && src/vcardToXML
```
If you want the source file on your PATH, you can either add `/path/to/vcardInCpp/src` to your PATH or run
`make install` to copy the source file to `/usr/bin`.
# TODO
Write my own parser for vcf files as none work that I have found or are commands which is not something I wasnt to mess with.
