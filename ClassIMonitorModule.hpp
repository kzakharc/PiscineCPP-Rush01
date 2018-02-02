//
// Created by Serhii Protsenko on 11/12/17.
//

#ifndef CLION_RUSH_IMONITORMODULE_HPP
#define CLION_RUSH_IMONITORMODULE_HPP


#include <string>

class IMonitorModule {

public:
	IMonitorModule();
	~IMonitorModule();

	virtual const char * 	get() = 0;

private:
	IMonitorModule & operator= (IMonitorModule const & ref);
	IMonitorModule(IMonitorModule const & ref);

protected:
	FILE *in;
	char buff[1024];
	std::string for_buff;

};


#endif

