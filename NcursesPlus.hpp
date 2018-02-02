// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NcursesPlus.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/12 16:38:18 by kzakharc          #+#    #+#             //
//   Updated: 2017/11/12 16:38:20 by kzakharc         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NCURSESPLUS_HPP
#define NCURSESPLUS_HPP

#include "ClassHUnameDate.hpp"
#include "ClassOsInfo.hpp"
#include "ClassCPU.hpp"
#include "ClassRAM.hpp"
#include "ClassNetwork.hpp"

class IMonitorDisplay;

#define HEIGHT		37
#define WIDTH		130

class NcursesPlus : public IMonitorDisplay {

private:

	WINDOW		*_w;
	WINDOW		*_q;
	NcursesPlus(NcursesPlus const &copy);
	NcursesPlus	&operator=(NcursesPlus const &copy);

public:

	NcursesPlus();
	~NcursesPlus();

	WINDOW 				*getWindow() const;
	void				print_unicorn();
	int					make_win(HUnameDate &userhost_name_time, osInfo &name_osInfo, CPU &cpu, RAM &ram, Network &net);
	void				makeBox();
	void				Uni();
	void				print_scale(CPU &cpu);
	virtual void		start();
};


#endif
