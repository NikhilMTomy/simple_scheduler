#include <iostream>
#include "Scheduler.h"

int main(int argc, char *argv[]) {
	Scheduler s;
	s.read_config();
	s.run();
}
