//
// Created by Serhii Protsenko on 11/11/17.
//

#include "ClassHUnameDate.hpp"

HUnameDate::HUnameDate()
{
	char nameHost[256];
	gethostname(nameHost, 256);
	_hostname = nameHost;

	char loginName[256];

	getlogin_r(loginName, 256);
	_username = loginName;

}

HUnameDate::~HUnameDate() {

}

HUnameDate::HUnameDate(HUnameDate const &ref) {
	*this = ref;
}

HUnameDate & HUnameDate::operator=(HUnameDate const &ref) {
	_username = ref.get_username();
	_hostname = ref.get_hostname();
	result = ref.getResult();
	tm = ref.getTm();
	in = ref.in;
	strcpy(buff, ref.buff);
	for_buff = ref.for_buff;
	return *this;
}

const char * HUnameDate::get_hostname() const {
	return _hostname.c_str();
}

const char * HUnameDate::get_username() const {
	return _username.c_str();
}

const char * HUnameDate::get() {

	result = std::time(nullptr);
	tm = std::asctime(std::localtime(&result));
	return tm.c_str() ;
}

time_t HUnameDate::getResult() const {
	return result;
}

const std::string &HUnameDate::getTm() const {
	return tm;
}





