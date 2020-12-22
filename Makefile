CC=g++
CFLAGS=-I ./include/ -std=c++11

all: pugixml.o vcardToXML.o myVcardReader.o
	$(CC) -o vcardToXML pugixml.o vcardToXML.o myVcardReader.o $(CFLAGS)

pugixml.o:
	$(CC) -c -o pugixml.o pugixml.cpp $(CFLAGS)
	
vcardToXML.o:
	$(CC) -c -o vcardToXML.o vcardToXML.cpp $(CFLAGS)
	
myVcardReader.o:
	$(CC) -c -o myVcardReader.o myVcardReader.cpp $(CFLAGS)
	
clean:
	rm -f *.o