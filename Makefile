CC=g++
CFLAGS=-I ./include/ -std=c++11

all: pugixml.o vcardToXML.o
	$(CC) -o vcardToXML pugixml.o vcardToXML.o $(CFLAGS)

pugixml.o:
	$(CC) -c -o pugixml.o pugixml.cpp $(CFLAGS)
	
vcardToXML.o:
	$(CC) -c -o vcardToXML.o vcardToXML.cpp $(CFLAGS)
	
clean:
	rm -f *.o