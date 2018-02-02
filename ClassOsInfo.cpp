//
// Created by Serhii Protsenko on 11/11/17.
//

#include "ClassOsInfo.hpp"

osInfo::osInfo() {
	if (!(in = popen("system_profiler SPSoftwareDataType", "r")))
	{
		std::cout << "ERROR: OsInfo constructor" << std::endl;
	}
	while (fgets(buff, sizeof(buff), in) != nullptr)
	{
		for_buff += static_cast<std::string>(buff);
	}
	pclose(in);

}

osInfo::~osInfo() {}

const char * osInfo::get() {
	return for_buff.c_str();
}

osInfo::osInfo(osInfo const & ref)
{
	in = ref.in;
	strcpy(buff, ref.buff);
	for_buff = ref.for_buff;
}

osInfo & osInfo::operator= (osInfo const & ref)
{
	in = ref.in;
	strcpy(buff, ref.buff);
	for_buff = ref.for_buff;
	return *this;
}