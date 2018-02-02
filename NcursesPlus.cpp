// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NcursesPlus.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/12 16:38:09 by kzakharc          #+#    #+#             //
//   Updated: 2017/11/12 16:38:10 by kzakharc         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "IMonitorDisplay.hpp"
#include "NcursesPlus.hpp"

NcursesPlus::NcursesPlus() {
	start();
	nodelay(_w, TRUE);
}

void NcursesPlus::start() {

	initscr();
	noecho();
	curs_set(0);
	color();
	this->_w = newwin(HEIGHT, WIDTH, 0, 0);
	this->_q = newwin(14, 40, 22, 80);
	print_unicorn();
	wrefresh(_w);
	wrefresh(_q);
}

void	NcursesPlus::makeBox() {

	int w = WIDTH;

	wattron(_w, COLOR_PAIR(1));
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
	wattroff(_w, COLOR_PAIR(1));
}

WINDOW *NcursesPlus::getWindow() const {
	return _w;
}

NcursesPlus::~NcursesPlus() {
	endwin();
}

int NcursesPlus::make_win(HUnameDate &userhost_name_time, osInfo &name_osInfo, CPU &cpu, RAM &ram, Network &net) {
	const char 		*buff1;
	int 			c;
	int 			i = 0;

	buff1 = ram.get();
	makeBox();
	wrefresh(_w);
	cpu.get();
	while (1) {
		wattron(_w, COLOR_PAIR(2));
		mvwprintw(_w, 2, 3, "%s", name_osInfo.get());
		mvwprintw(_w, 18, 3, "%s", cpu.getStatic_data_cpu());
		wattroff(_w, COLOR_PAIR(2));
		wattron(_w, COLOR_PAIR(2));
		mvwprintw(_w, 2, 64, "Host name:");
		wattroff(_w, COLOR_PAIR(2));
		mvwprintw(_w, 2, 77, "%s", userhost_name_time.get_hostname());
		wattron(_w, COLOR_PAIR(2));
		mvwprintw(_w, 3, 64, "User name:");
		wattroff(_w, COLOR_PAIR(2));
		mvwprintw(_w, 3, 77, "%s", userhost_name_time.get_username());
		wattron(_w, COLOR_PAIR(2));
		mvwprintw(_w, 5, 64, "Time info:");
		wattroff(_w, COLOR_PAIR(2));
		mvwprintw(_w, 5, 77, "%s", userhost_name_time.get());
		if (i == 3) {
			cpu.get();
			buff1 = ram.get();
			print_scale(cpu);
			mvwprintw(_w, 8, 64, "%s", buff1);
			i = 0;
		}
		else {
			print_scale(cpu);
			mvwprintw(_w, 8, 64, "%s", buff1);
		}
		mvwprintw(_w, 10, 64, "%s", net.get());
		wattron(_w, COLOR_PAIR(3));
		mvwprintw(_w, 35, 110, "Press ESC to exit");
		wattroff(_w, COLOR_PAIR(3));
		makeBox();
		wrefresh(_w);
		Uni();
		wrefresh(_q);
		c = wgetch(_w);
		if (c == 27)
			return -1;
		i++;
	}
}

void NcursesPlus::print_scale(CPU &cpu) {

	wattron(_w, COLOR_PAIR(2));
	mvwprintw(_w, 13, 64, "CPU:");
	wattroff(_w, COLOR_PAIR(2));
	if (cpu.getUser() <= 10) {
		mvwprintw(_w, 15, 64, "%.1f%% ", cpu.getUser());
		wattron(_w, COLOR_PAIR(6));
		mvwprintw(_w, 15, 70, "|                ");
		wattroff(_w, COLOR_PAIR(6));
	}
	if (cpu.getUser() <= 20) {
		mvwprintw(_w, 15, 64, "%.1f%% ", cpu.getUser());
		wattron(_w, COLOR_PAIR(6));
		mvwprintw(_w, 15, 70, "||                ");
		wattroff(_w, COLOR_PAIR(6));
	}
	else if (cpu.getUser() <= 30) {
		mvwprintw(_w, 15, 64, "%.1f%% ", cpu.getUser());
		wattron(_w, COLOR_PAIR(6));
		mvwprintw(_w, 15, 70, "|||                   ");
		wattroff(_w, COLOR_PAIR(6));
	}
	else if (cpu.getUser() <= 40) {
		mvwprintw(_w, 15, 64, "%.1f%% ", cpu.getUser());
		wattron(_w, COLOR_PAIR(7));
		mvwprintw(_w, 15, 70, "||||                     ");
		wattroff(_w, COLOR_PAIR(7));
	}
	else if (cpu.getUser() <= 50) {
		mvwprintw(_w, 15, 64, "%.1f%% ", cpu.getUser());
		wattron(_w, COLOR_PAIR(7));
		mvwprintw(_w, 15, 70, "|||||                      ");
		wattroff(_w, COLOR_PAIR(7));
	}
	else if (cpu.getUser() <= 60) {
		mvwprintw(_w, 15, 64, "%.1f%% ", cpu.getUser());
		wattron(_w, COLOR_PAIR(7));
		mvwprintw(_w, 15, 70, "||||||                      ");
		wattroff(_w, COLOR_PAIR(7));
	}
	else if (cpu.getUser() <= 70) {
		mvwprintw(_w, 15, 64, "%.1f%% ", cpu.getUser());
		wattron(_w, COLOR_PAIR(7));
		mvwprintw(_w, 15, 70, "|||||||                 ");
		wattroff(_w, COLOR_PAIR(7));
	}
	else if (cpu.getUser() <= 80) {
		mvwprintw(_w, 15, 64, "%.1f%% ", cpu.getUser());
		wattron(_w, COLOR_PAIR(8));
		mvwprintw(_w, 15, 70, "||||||||                ");
		wattroff(_w, COLOR_PAIR(8));
	}
	else if (cpu.getUser() <= 90) {
		mvwprintw(_w, 15, 64, "%.1f%% ", cpu.getUser());
		wattron(_w, COLOR_PAIR(8));
		mvwprintw(_w, 15, 70, "|||||||||                ");
		wattroff(_w, COLOR_PAIR(8));
	}
	else if (cpu.getUser() <= 100) {
		mvwprintw(_w, 15, 64, "%.1f%% ", cpu.getUser());
		wattron(_w, COLOR_PAIR(8));
		mvwprintw(_w, 15, 70, "||||||||||             ");
		wattroff(_w, COLOR_PAIR(8));
	}

	///////////////////////////////////////////////////////////////


	if (cpu.getSys() <= 10) {
		mvwprintw(_w, 17, 64, "%.1f%% ", cpu.getSys());
		wattron(_w, COLOR_PAIR(6));
		mvwprintw(_w, 17, 70, "|                    ");
		wattroff(_w, COLOR_PAIR(6));
	}
	if (cpu.getSys() <= 20) {
		mvwprintw(_w, 17, 64, "%.1f%% ", cpu.getSys());
		wattron(_w, COLOR_PAIR(6));
		mvwprintw(_w, 17, 70, "||                 ");
		wattroff(_w, COLOR_PAIR(6));
	}
	else if (cpu.getSys() <= 30) {
		mvwprintw(_w, 17, 64, "%.1f%% ", cpu.getSys());
		wattron(_w, COLOR_PAIR(6));
		mvwprintw(_w, 17, 70, "|||               ");
		wattroff(_w, COLOR_PAIR(6));
	}
	else if (cpu.getSys() <= 40) {
		mvwprintw(_w, 17, 64, "%.1f%% ", cpu.getSys());
		wattron(_w, COLOR_PAIR(7));
		mvwprintw(_w, 17, 70, "||||                 ");
		wattroff(_w, COLOR_PAIR(7));
	}
	else if (cpu.getSys() <= 50) {
		mvwprintw(_w, 17, 64, "%.1f%% ", cpu.getSys());
		wattron(_w, COLOR_PAIR(7));
		mvwprintw(_w, 17, 70, "|||||                  ");
		wattroff(_w, COLOR_PAIR(7));
	}
	else if (cpu.getSys() <= 60) {
		mvwprintw(_w, 17, 64, "%.1f%% ", cpu.getSys());
		wattron(_w, COLOR_PAIR(7));
		mvwprintw(_w, 17, 70, "||||||                  ");
		wattroff(_w, COLOR_PAIR(7));
	}
	else if (cpu.getSys() <= 70) {
		mvwprintw(_w, 17, 64, "%.1f%% ", cpu.getSys());
		wattron(_w, COLOR_PAIR(7));
		mvwprintw(_w, 17, 70, "|||||||               ");
		wattroff(_w, COLOR_PAIR(7));
	}
	else if (cpu.getSys() <= 80) {
		mvwprintw(_w, 17, 64, "%.1f%% ", cpu.getSys());
		wattron(_w, COLOR_PAIR(8));
		mvwprintw(_w, 17, 70, "||||||||                ");
		wattroff(_w, COLOR_PAIR(8));
	}
	else if (cpu.getSys() <= 90) {
		mvwprintw(_w, 17, 64, "%.1f%% ", cpu.getSys());
		wattron(_w, COLOR_PAIR(8));
		mvwprintw(_w, 17, 70, "|||||||||            ");
		wattroff(_w, COLOR_PAIR(8));
	}
	else if (cpu.getSys() <= 100) {
		mvwprintw(_w, 17, 64, "%.1f%% ", cpu.getSys());
		wattron(_w, COLOR_PAIR(8));
		mvwprintw(_w, 17, 70, "||||||||||              ");
		wattroff(_w, COLOR_PAIR(8));
	}

	////////////////////////////////////////////////////////////////////

	if (cpu.getIdle() <= 10) {
		mvwprintw(_w, 19, 64, "%.1f%% ", cpu.getIdle());
		wattron(_w, COLOR_PAIR(6));
		mvwprintw(_w, 19, 70, "|                    ");
		wattroff(_w, COLOR_PAIR(6));
	}
	if (cpu.getIdle() <= 20) {
		mvwprintw(_w, 19, 64, "%.1f%% ", cpu.getIdle());
		wattron(_w, COLOR_PAIR(6));
		mvwprintw(_w, 19, 70, "||                 ");
		wattroff(_w, COLOR_PAIR(6));
	}
	else if (cpu.getIdle() <= 30) {
		mvwprintw(_w, 19, 64, "%.1f%% ", cpu.getIdle());
		wattron(_w, COLOR_PAIR(6));
		mvwprintw(_w, 19, 70, "|||               ");
		wattroff(_w, COLOR_PAIR(6));
	}
	else if (cpu.getIdle() <= 40) {
		mvwprintw(_w, 19, 64, "%.1f%% ", cpu.getIdle());
		wattron(_w, COLOR_PAIR(7));
		mvwprintw(_w, 19, 70, "||||                 ");
		wattroff(_w, COLOR_PAIR(7));
	}
	else if (cpu.getIdle() <= 50) {
		mvwprintw(_w, 19, 64, "%.1f%% ", cpu.getIdle());
		wattron(_w, COLOR_PAIR(7));
		mvwprintw(_w, 19, 70, "|||||                  ");
		wattroff(_w, COLOR_PAIR(7));
	}
	else if (cpu.getIdle() <= 60) {
		mvwprintw(_w, 19, 64, "%.1f%% ", cpu.getIdle());
		wattron(_w, COLOR_PAIR(7));
		mvwprintw(_w, 19, 70, "||||||                  ");
		wattroff(_w, COLOR_PAIR(7));
	}
	else if (cpu.getIdle() <= 70) {
		mvwprintw(_w, 19, 64, "%.1f%% ", cpu.getIdle());
		wattron(_w, COLOR_PAIR(7));
		mvwprintw(_w, 19, 70, "|||||||               ");
		wattroff(_w, COLOR_PAIR(7));
	}
	else if (cpu.getIdle() <= 80) {
		mvwprintw(_w, 19, 64, "%.1f%% ", cpu.getIdle());
		wattron(_w, COLOR_PAIR(8));
		mvwprintw(_w, 19, 70, "||||||||                ");
		wattroff(_w, COLOR_PAIR(8));
	}
	else if (cpu.getIdle() <= 90) {
		mvwprintw(_w, 19, 64, "%.1f%% ", cpu.getIdle());
		wattron(_w, COLOR_PAIR(8));
		mvwprintw(_w, 19, 70, "|||||||||            ");
		wattroff(_w, COLOR_PAIR(8));
	}
	else if (cpu.getIdle() <= 100) {
		mvwprintw(_w, 19, 64, "%.1f%% ", cpu.getIdle());
		wattron(_w, COLOR_PAIR(8));
		mvwprintw(_w, 19, 70, "||||||||||              ");
		wattroff(_w, COLOR_PAIR(8));
	}
}

void NcursesPlus::print_unicorn() {
	int y = 3;
	int x = 18;
	std::string uni = "                               ,|     \n"
			"                             //|                              ,|\n"
			"                           //,/                             -~ |\n"
			"                         // / |                         _-~   /  ,\n"
			"                       /'/ / /                       _-~   _/_-~ |\n"
			"                      ( ( / /'                   _ -~     _-~ ,/'\n"
			"                       \\~\\/'/|             __--~~__--\\ _-~  _/,\n"
			"               ,,)))))));, \\/~-_     __--~~  --~~  __/~  _-~ /\n"
			"            __))))))))))))));,>/\\   /        __--~~  \\-~~ _-~\n"
			"           -\\(((((''''(((((((( >~\\/     --~~   __--~' _-~ ~|\n"
			"  --==//////((''  .     `)))))), /     ___---~~  ~~\\~~__--~ \n"
			"          ))| @    ;-.     (((((/           __--~~~'~~/\n"
			"          ( `|    /  )      )))/      ~~~~~__\\__---~~__--~~--_\n"
			"             |   |   |       (/      ---~~~/__-----~~  ,;::'  \\         ,\n"
			"             o_);   ;        /      ----~~/           \\,-~~~\\  |       /|\n"
			"                   ;        (      ---~~/         `:::|      |;|      < >\n"
			"                  |   _      `----~~~~'      /      `:|       \\;\\_____// \n"
			"            ______/\\/~    |                 /        /         ~------~\n"
			"          /~;;.____/;;'  /          ___----(   `;;;/               \n"
			"         / //  _;______;'------~~~~~    |;;/\\    /          \n"
			"        //  | |                        /  |  \\;;,\\              \n"
			"       (<_  | ;                      /',/-----'  _>\n"
			"        \\_| ||_                     //~;~~~~~~~~~ \n"
			"            `\\_|                   (,~~ \n"
			"                                    \\~\\ \n"
			"                                     ~~ \n"
			"";
	wattron(_w, COLOR_PAIR(3));
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
	wattroff(_w, COLOR_PAIR(3));
	wclear(_w);
}

void NcursesPlus::Uni() {
	const char * uni = "            a@@@@a\n"
			"        a@@@@@@@@@@@@a\n"
			"      a@@@@@@by@@@@@@@@a\n"
			"    a@@@@@S@C@E@S@W@@@@@@a\n"
			"    @@@@@@@@@@@@@@@@@@@@@@\n"
			"     `@@@@@@`\\\\//'@@@@@@'\n"
			"          ,,/ || \\,,\n"
			"         /(-\\ || /.)m   \n"
			"    ,---' /`-'||`-'\\ `----,\n"
			"   /( )__))   ||   ((,==( )\\\n"
			"_ /_//___\\\\ __|| ___\\\\ __\\\\ ___\n"
			"    ``    `` /MM\\   ''   ''";
	wattron(_q, COLOR_PAIR(3));
	mvwprintw(_q, 0, 0, "%s", uni);
	wattroff(_q, COLOR_PAIR(3));
}
