// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IMonitorDisplay.hpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/12 11:59:19 by kzakharc          #+#    #+#             //
//   Updated: 2017/11/12 11:59:21 by kzakharc         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PISCINE_CPP_IMONITORDISPLAY_HPP
#define PISCINE_CPP_IMONITORDISPLAY_HPP

#include <string>
#include <iostream>
#include <ncurses.h>
#include <unistd.h>

class IMonitorDisplay {

protected:

	IMonitorDisplay();
	IMonitorDisplay(IMonitorDisplay const &copy);
	virtual IMonitorDisplay	&operator=(IMonitorDisplay const &copy);
	virtual ~IMonitorDisplay();

	virtual void		start() = 0;
	void				color();
};


#endif //PISCINE_CPP_IMONITORDISPLAY_HPP
