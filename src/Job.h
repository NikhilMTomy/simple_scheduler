#ifndef _JOB_H_
#define _JOB_H_

#include <string>

class Job {
	private:
		std::string _name;
		std::string _user;
		std::string _executable_file;
		int         _execution_factor;
	public:
		Job();
		Job(std::string, std::string, std::string, int);
		~Job();

		std::string get_name() const;
		std::string get_user() const;
		std::string get_executable_file() const;
		int get_execution_factor() const;

		void set_name(std::string);
		void set_user(std::string);
		void set_executable_file(std::string);
		void set_execution_factor(int);
};

#endif
