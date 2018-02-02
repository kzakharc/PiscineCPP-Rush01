//
// Created by Serhii Protsenko on 11/11/17.
//

#ifndef CLION_RUSH_STEP_HPP
#define CLION_RUSH_STEP_HPP

#include <iostream>
#include <string>
#include <unistd.h>

#include "ClassIMonitorModule.hpp"

class HUnameDate : public IMonitorModule
{

public:

	HUnameDate();
	~HUnameDate();

	const char * 	get_hostname() const;
	const char * 	get_username() const;

	const char * 	get();


	time_t getResult() const;

	const std::string &getTm() const;


private:
    std::string		_hostname;
	std::string		_username;

	std::time_t result;
	std::string tm;

	HUnameDate(HUnameDate const & ref);
	HUnameDate& operator= (HUnameDate const & ref);

};


#endif
