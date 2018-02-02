//
// Created by Serhii Protsenko on 11/12/17.
//

#include "ClassNetwork.hpp"


Network::Network() {

}

Network::~Network() {

}

const char * Network::get()
{
	if (!(in = popen("/usr/bin/top | /usr/bin/head -n9 | /usr/bin/grep 'Network'", "r")))
	{
		std::cout << "ERROR: Network constructor" << std::endl;
	}
	fgets(buff, sizeof(buff), in);
	pclose(in);
	return buff;
}

Network::Network(Network const & ref)
{
	in = ref.in;
	strcpy(buff, ref.buff);
	for_buff = ref.for_buff;
}

Network & Network::operator= (Network const & ref)
{
	in = ref.in;
	strcpy(buff, ref.buff);
	for_buff = ref.for_buff;
	return *this;
}