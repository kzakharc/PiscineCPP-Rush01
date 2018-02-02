// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NcursesMonitor.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/11 16:54:31 by kzakharc          #+#    #+#             //
//   Updated: 2017/11/11 16:54:33 by kzakharc         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NCURSESMONITOR_HPP
#define NCURSESMONITOR_HPP

#include "ClassHUnameDate.hpp"
#include "ClassOsInfo.hpp"
#include "ClassCPU.hpp"
#include "ClassRAM.hpp"
#include "ClassNetwork.hpp"

class IMonitorDisplay;

#define HEIGHT		37
#define WIDTH		130

class NcursesMonitor : public IMonitorDisplay {

private:

	WINDOW		*_w;
	NcursesMonitor(NcursesMonitor const &copy);
	NcursesMonitor	&operator=(NcursesMonitor const &copy);

public:

	NcursesMonitor();
	~NcursesMonitor();

	WINDOW 				*getWindow() const;
	void				print_unicorn();
	int					make_win(HUnameDate &userhost_name_time, osInfo &name_osInfo, CPU &cpu, RAM &ram, Network &net);
	void				makeBox();
	virtual void		start();
};


#endif
