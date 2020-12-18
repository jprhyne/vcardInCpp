CC=g++
CFLAGS=-I
DEPS = pugixml.hpp

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

default: pugixml.o vcardToXML.o
	$(CC) -o vcardToXML pugixml.o vcardToXML.o
