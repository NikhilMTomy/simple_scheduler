CC:=g++
FLAGS:=--std=c++17
OUTPUT:=build/simple_scheduler
SOURCE:=src/main.cc src/Job.cc src/Scheduler.cc
HEADER:=src/Job.h src/Scheduler.h
BINARY:=/usr/local/bin/simple_scheduler
CONFIG_SRC:=config/simple_scheduler.conf
CONFIG_DEST:=/etc/simple_scheduler.conf

all: $(SOURCE) $(HEADER)
	@echo Building
	$(CC) $(SOURCE) -o $(OUTPUT) $(FLAGS)
	@echo Configuring
	sed -i 's/$$user/${USER}/' config/simple_scheduler.conf

install:
	cp $(OUTPUT) $(BINARY)
	cp $(CONFIG_SRC) $(CONFIG_DEST)

uninstall:
	rm $(BINARY)

clean:
	rm $(OUTPUT)
