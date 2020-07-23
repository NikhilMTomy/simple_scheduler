#include "Scheduler.h"

Scheduler::Scheduler():
	_global_config_file("/etc/my_scheduler.conf"), _count(0) {}

Scheduler::~Scheduler() {}

Job
Scheduler::parse_config_line(std::string line) {
	char *token, *c;
	Job new_job;
	
	try {
		token = strtok((char*)line.c_str(), "\t");
		new_job.set_name(token);
		token = strtok(NULL, "\t");
		new_job.set_user(token);
		token = strtok(NULL, "\t");
		new_job.set_execution_factor(atoi(token));
		token = strtok(NULL, "\t");
		new_job.set_executable_file(token);
		return new_job;
	} catch (std::exception& e) {
		return Job();
	}
}

void
Scheduler::read_config() {
	std::fstream config_file_r;
	std::string line;

	config_file_r.open(_global_config_file, std::ios::in);
	while (std::getline(config_file_r, line)) {
		if (line[0] != '#' && line.length() > 0) {
			_job_list.push_back(parse_config_line(line));
		}
	}
}

void
Scheduler::display_all_jobs() {
	for (const Job & j : _job_list) {
		std::cout << "Name : " << j.get_name() << std::endl;
		std::cout << "User : " << j.get_user() << std::endl;
		std::cout << "Execution Factor : " << j.get_execution_factor() << std::endl;
		std::cout << "Executable File  : " << j.get_executable_file() << std::endl;
		std::cout << std::endl << std::endl;
	}
}

void 
Scheduler::run_jobs() {
	std::stringstream ss;
	for (const Job & j : _job_list) {
		if (_count % j.get_execution_factor() == 0) {
			std::cout << "Running [" << j.get_name() << "]" << std::endl;
			ss.str(std::string());
			ss << "runuser -l " << j.get_user() << " -c '" << j.get_executable_file() << "'";
			std::system((char*)ss.str().c_str());
		}
	}
}

void
Scheduler::run() {
	while (1) {
		run_jobs();
		std::this_thread::sleep_for(std::chrono::seconds(60));
		_count++;
	}
}
