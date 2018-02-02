//
// Created by Serhii Protsenko on 11/12/17.
//

#include "ClassIMonitorModule.hpp"

IMonitorModule::IMonitorModule() {}

IMonitorModule::~IMonitorModule() {}

IMonitorModule::IMonitorModule(IMonitorModule const &ref) {
	*this = ref;
}

IMonitorModule & IMonitorModule::operator=(IMonitorModule const &ref) {
	in = ref.in;
	strcpy(buff, ref.buff);
	for_buff = ref.for_buff;
	return *this;
}

