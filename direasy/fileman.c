#include "mylib.h"
void main()
{
	WINDOW *win1 , *win2, *menu;
	winlock = TRUE;
	ptr1=ptr2=1;
	sprintf(path1,"/");
	sprintf(path2,"/");
	shift1=shift2=0;
	int ch;
	initscr();
	chdir("/");
	cbreak();
	refresh();
	noecho();
	curs_set(1);
	start_color();
	keypad(stdscr,TRUE);
	init_pair(1,COLOR_YELLOW,COLOR_BLUE);
	init_pair(2,COLOR_BLACK,COLOR_GREEN);
	{
		win1 = newwin(LINES - 3,COLS/2,0,0);
		box(win1,0,0);
		wbkgd(win1,COLOR_PAIR(1));
		wrefresh(win1);
	}
	{
		win2 = newwin(LINES - 3,COLS/2,0,COLS/2);
		box(win2,0,0);
		wbkgd(win2,COLOR_PAIR(1));
		wrefresh(win2);
	}
	{
		menu = newwin(3,COLS,LINES -3,0);
		box(menu,0,0);
		wbkgd(menu,COLOR_PAIR(2));
		mvwprintw(menu,1,1,"F1 - CHANGE WINDOW | F4 - QUIT");
		wrefresh(menu);
	}
	init_windows(win1,win2);
	wmove(win1,1,1);
	wrefresh(win1);
	while((ch = getch()) != KEY_F(4))
	{
		switch(ch)
		{
			case KEY_F(1):
			change_win(win1,win2);
			break;
			case '\n':
			change_dir(win1,win2);
			break;
			case KEY_DOWN:
			step_down(win1,win2);
			break;
		}
	}
	delwin(win1);
	delwin(win2);
	delwin(menu);
	endwin();
}