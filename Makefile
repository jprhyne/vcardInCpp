CC=g++
CFLAGS=-I ./include/ -std=c++11 -g

all: pugixml.o vcardToXML.o myVcardReader.o
	$(CC) -o vcardToXML pugixml.o vcardToXML.o myVcardReader.o $(CFLAGS)

pugixml.o:
	$(CC) -c -o pugixml.o pugixml.cpp $(CFLAGS)
	
vcardToXML.o:
	$(CC) -c -o vcardToXML.o vcardToXML.cpp $(CFLAGS)
	
myVcardReader.o:
	$(CC) -c -o myVcardReader.o myVcardReader.cpp $(CFLAGS)
	
cleanall:
	rm -f *.o

clean:
	mv pugixml.o pugixml.bak
	rm -f *.o
	mv pugixml.bak pugixml.o
