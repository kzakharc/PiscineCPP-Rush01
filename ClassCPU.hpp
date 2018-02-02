//
// Created by Serhii Protsenko on 11/11/17.
//

#ifndef CLION_RUSH_CPU_HPP
#define CLION_RUSH_CPU_HPP

#include "ClassHUnameDate.hpp"

class CPU : public IMonitorModule
{

public:
	const char * getStatic_data_cpu() const;

	CPU();
	~CPU();

	const char * get();
	float getUser() const;
	float getSys() const;
	float getIdle() const;


private:
	CPU(CPU const & ref);
	CPU & operator= (CPU const & ref);
	std::string new_str;
	float 	user;
	float 	sys;
	float 	idle;

};


#endif //CLION_RUSH_CPU_H
