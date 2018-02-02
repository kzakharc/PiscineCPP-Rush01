//
// Created by Serhii Protsenko on 11/12/17.
//

#include "ClassRAM.hpp"

RAM::RAM(){}

RAM::~RAM(){}


const char * RAM::get() {

	if (!(in = popen("top -l 1 | grep \"PhysMem:\" ", "r")))
	{
		std::cout << "ERROR: RAM constructor" << std::endl;
	}
	fgets(buff, sizeof(buff), in);
	pclose(in);
	return buff;

}

RAM::RAM(RAM const & ref)
{
	in = ref.in;
	strcpy(buff, ref.buff);
	for_buff = ref.for_buff;
}

RAM & RAM::operator= (RAM const & ref)
{
	in = ref.in;
	strcpy(buff, ref.buff);
	for_buff = ref.for_buff;
	return *this;
}