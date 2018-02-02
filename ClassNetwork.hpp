//
// Created by Serhii Protsenko on 11/12/17.
//

#ifndef CLION_RUSH_CLASSNETWORK_HPP
#define CLION_RUSH_CLASSNETWORK_HPP

#include "ClassHUnameDate.hpp"

class Network : public IMonitorModule
{

private:
	Network(Network const & ref);
	Network & operator= (Network const & ref);

public:
	Network();
	~Network();

	const char *  	get();

};


#endif
