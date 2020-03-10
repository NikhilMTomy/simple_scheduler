CC:=g++
FLAGS:=`pkg-config --cflags --libs libnotify`
OUTPUT:=build/executable
SOURCE:=src/main.cc
BINARY:=/usr/local/bin/executable

all: $(SOURCE)
	$(CC) $(SOURCE) -o $(OUTPUT) $(FLAGS)

install:
	cp $(OUTPUT) $(BINARY)

uninstall:
	rm $(BINARY)

clean:
	rm $(OUTPUT)
