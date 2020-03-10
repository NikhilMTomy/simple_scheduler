#ifndef _JOBS_H_
#define _JOBS_H_

class Jobs {
	private:
		std::string _name;
		std::string _user;
		std::int    _execution_factor;
		std::string _executable_file;
	public:
		Jobs();
		~Jobs();
}

#endif _JOBS_H_
