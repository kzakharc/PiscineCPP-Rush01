//
// Created by Serhii Protsenko on 11/11/17.
//

#ifndef CLION_RUSH_OSINFO_H
#define CLION_RUSH_OSINFO_H

#include "ClassHUnameDate.hpp"

class osInfo : public IMonitorModule
{

private:
	osInfo(osInfo const & ref);
	osInfo & operator= (osInfo const & ref);

public:
	osInfo();
	~osInfo();

	const char *  	get();

};


#endif
