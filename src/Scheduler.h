#ifndef _SCHEDULER_H_
#define _SCHEDULER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <list>
#include <exception>
#include <cstdlib>
#include <sstream>
#include <chrono>
#include <thread>

#include "Job.h"

class Scheduler {
	private:
		std::string _global_config_file;
		std::string _config_delimiter;
		std::list<Job> _job_list;
		int _count;
		Job parse_config_line(std::string);
		void run_jobs();
		
	public:
		Scheduler();
		~Scheduler();
		void read_config();
		void display_all_jobs();
		void run();
};

#endif
