//
// Created by Serhii Protsenko on 11/12/17.
//

#ifndef CLION_RUSH_RAM_H
#define CLION_RUSH_RAM_H

#include "ClassHUnameDate.hpp"

class RAM : public IMonitorModule
{

private:
	RAM & operator= (RAM const & ref);
	RAM(RAM const & ref);

public:
	RAM();
	~RAM();

	const char *	get();

};


#endif
