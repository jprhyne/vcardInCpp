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
make && ./vcardToXML
```
# TODO
Write my own parser for vcf files as none work that I have found
