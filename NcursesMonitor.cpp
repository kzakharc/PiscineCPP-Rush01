// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Step_1.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/11 16:54:10 by kzakharc          #+#    #+#             //
//   Updated: 2017/11/11 16:54:12 by kzakharc         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "IMonitorDisplay.hpp"
#include "NcursesMonitor.hpp"

NcursesMonitor::NcursesMonitor() {
	start();
	nodelay(_w, TRUE);
}

void NcursesMonitor::start() {

	initscr();
	noecho();
	curs_set(0);
	color();
	this->_w = newwin(HEIGHT, WIDTH, 0, 0);
	print_unicorn();
	wrefresh(_w);
}

void	NcursesMonitor::makeBox() {

	int w = WIDTH;

	wattron(_w, COLOR_PAIR(5));
	while (w--) {
		mvwprintw(_w, 0, w, " ");
		mvwprintw(_w, HEIGHT - 1, w, " ");
	}
	w = WIDTH / 2 - 6;
	while (w--) {
		mvwprintw(_w, HEIGHT / 2 - 2, w, " ");
	}
	w = HEIGHT;
	while (w--) {
		mvwprintw(_w, w, 0, "  ");
		mvwprintw(_w, w, WIDTH - 2, "  ");
		mvwprintw(_w, w, WIDTH / 2 - 6, "  ");
	}
	wattroff(_w, COLOR_PAIR(4));
}

WINDOW *NcursesMonitor::getWindow() const {
	return _w;
}

NcursesMonitor::~NcursesMonitor() {
	endwin();
}

int NcursesMonitor::make_win(HUnameDate &userhost_name_time, osInfo &name_osInfo, CPU &cpu, RAM &ram, Network &net) {
	const char 		*buff;
	const char 		*buff1;
	int 			c;
	int 			i = 0;

	buff = cpu.get();
	buff1 = ram.get();
	makeBox();
	wrefresh(_w);
	while (1) {
		mvwprintw(_w, 2, 3, "%s", name_osInfo.get());
		mvwprintw(_w, 18, 3, "%s", cpu.getStatic_data_cpu());
		wattron(_w, COLOR_PAIR(8));
		mvwprintw(_w, 2, 64, "Host name:");
		wattroff(_w, COLOR_PAIR(8));
		mvwprintw(_w, 2, 77, "%s", userhost_name_time.get_hostname());
		wattron(_w, COLOR_PAIR(8));
		mvwprintw(_w, 3, 64, "User name:");
		wattroff(_w, COLOR_PAIR(8));
		mvwprintw(_w, 3, 77, "%s", userhost_name_time.get_username());
		wattron(_w, COLOR_PAIR(8));
		mvwprintw(_w, 5, 64, "Time info:");
		wattroff(_w, COLOR_PAIR(8));
		mvwprintw(_w, 5, 77, "%s", userhost_name_time.get());
		if (i == 3) {
			buff = cpu.get();
			buff1 = ram.get();
			mvwprintw(_w, 8, 64, "%s", buff);
			mvwprintw(_w, 10, 64, "%s", buff1);
			i = 0;
		}
		else {
			mvwprintw(_w, 8, 64, "%s", buff);
			mvwprintw(_w, 10, 64, "%s", buff1);
		}
		mvwprintw(_w, 12, 64, "%s", net.get());
		wattron(_w, COLOR_PAIR(8));
		mvwprintw(_w, 35, 110, "Press ESC to exit");
		wattroff(_w, COLOR_PAIR(8));
		makeBox();
		wrefresh(_w);
		c = wgetch(_w);
		if (c == 27)
			return -1;
		i++;
	}
}

void NcursesMonitor::print_unicorn() {
	int y = 7;
	int x = 18;
	std::string uni = "                  <<<<>>>>>>           .----------------------------.\n"
			"               _>><<<<>>>>>>>>>       /               _____________)\n"
			"      \\|/      \\<<<<<  < >>>>>>>>>   /            _______________)\n"
			"-------*--===<=<<           <<<<<<<>/         _______________)\n"
			"      /|\\     << @    _/      <<<<</       _____________)\n"
			"             <  \\    /  \\      >>>/      ________)  ____\n"
			"                 |  |   |       </      ______)____((- \\\\\\\\\n"
			"                 o_|   /        /      ______)         \\  \\\\\\\\    \\\\\\\\\\\\\\\n"
			"                      |  ._    (      ______)           \\  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n"
			"                      | /       `----------'    /       /     \\\\\\\\\\\\\\     \\\\\n"
			"              .______/\\/     /                 /       /          \\\\\\\n"
			"             / __.____/    _/         ________(       /\\\n"
			"            / / / ________/`---------'         \\     /  \\_\n"
			"           / /  \\ \\                             \\   \\ \\_  \\\n"
			"          ( <    \\ \\                             >  /    \\ \\\n"
			"           \\/      \\\\_                          / /       > )\n"
			"                    \\_|                        / /       / /\n"
			"                                             _//       _//\n"
			"                                            /_|       /_|";
	wattron(_w, COLOR_PAIR(4));
	for (size_t i = 0; i < uni.size(); i++)
	{
		if (uni[i] == '\n')
		{
			y++;
			x = 18;
			wrefresh(_w);
			napms(100);
		}
		mvwaddch(_w, y, x++, uni[i]);
	}
	napms(1100);
	wattroff(_w, COLOR_PAIR(4));
	wclear(_w);
}

