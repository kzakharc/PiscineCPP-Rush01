// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IMonitorDisplay.cpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/12 11:59:27 by kzakharc          #+#    #+#             //
//   Updated: 2017/11/12 11:59:29 by kzakharc         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "IMonitorDisplay.hpp"

IMonitorDisplay::IMonitorDisplay() {

}

IMonitorDisplay::IMonitorDisplay(IMonitorDisplay const &copy) {
	*this = copy;
}

IMonitorDisplay &IMonitorDisplay::operator=(IMonitorDisplay const &copy) {
	(void)copy;
	return *this;
}

void IMonitorDisplay::color() {
	start_color();
	init_pair(1, COLOR_WHITE, 24);
	init_pair(2, 74, COLOR_BLACK);
	init_pair(3, 176, COLOR_BLACK);
	init_pair(4, 229, COLOR_BLACK);
	init_pair(5, 229, 8);
	init_pair(6, COLOR_GREEN, COLOR_BLACK);
	init_pair(7, COLOR_YELLOW, COLOR_BLACK);
	init_pair(8, COLOR_RED, COLOR_BLACK);
	init_pair(8, 8, COLOR_BLACK);
}

IMonitorDisplay::~IMonitorDisplay() {

}

