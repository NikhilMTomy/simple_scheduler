#include "Job.h"

Job::Job() {}
Job::Job(
	std::string name,
	std::string user,
	std::string executable_file,
	int execution_factor) {
	_name = name;
	_user = user;
	_executable_file = executable_file;
	_execution_factor = execution_factor;
}

std::string
Job::get_name() const {
	return _name;
}
void
Job::set_name(std::string name) {
	_name = name;
}

std::string
Job::get_user() const {
	return _user;
}
void
Job::set_user(std::string user) {
	_user = user;
}

std::string
Job::get_executable_file() const {
	return _executable_file;
}
void
Job::set_executable_file(std::string executable_file) {
	_executable_file = executable_file;
}

int
Job::get_execution_factor() const {
	return _execution_factor;
}
void
Job::set_execution_factor(int execution_factor) {
	_execution_factor = execution_factor;
}

Job::~Job() {}
