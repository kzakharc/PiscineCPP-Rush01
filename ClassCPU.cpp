//
// Created by Serhii Protsenko on 11/11/17.
//

#include "ClassCPU.hpp"

CPU::CPU(): user(0), sys(0), idle(0) {
	if (!(in = popen("system_profiler -detailLevel full SPHardwareDataType", "r")))
	{
		std::cout << "ERROR: CPU constructor" << std::endl;
	}
	while (fgets(buff, sizeof(buff), in) != NULL)
	{
		for_buff += static_cast<std::string>(buff);
	}

	pclose(in);
}



CPU::~CPU() {
}

const char * CPU::get()
{
	if (!(in = popen("top -l 1 | grep \"CPU usage\" ", "r")))
	{
		std::cout << "ERROR: CPU constructor" << std::endl;
	}
	fgets(buff, sizeof(buff), in);
	pclose(in);

	new_str = buff;
	user = 	atof(new_str.c_str() + 11);
	size_t  it = new_str.find("user, ", 11);
	sys = atof(new_str.c_str() + it + 6);
	it = new_str.find("sys, ", it);
	idle = atof(new_str.c_str() + it + 5);

	return buff;
}

const char * CPU::getStatic_data_cpu() const {
	return for_buff.c_str();
}

CPU::CPU(CPU const & ref)
{
	in = ref.in;
	strcpy(buff, ref.buff);
	for_buff = ref.for_buff;
}

CPU & CPU::operator= (CPU const & ref)
{
	in = ref.in;
	strcpy(buff, ref.buff);
	for_buff = ref.for_buff;
	return *this;
}

float CPU::getUser() const {
	return user;
}

float CPU::getSys() const {
	return sys;
}

float CPU::getIdle() const {
	return idle;
}



