#include "mylib.h"
void main(int argc, char *argv[])
{
	WINDOW *win, *win_2;
	int ch;
	initscr();
	cbreak();
	refresh();
	sprintf(argum,"./%s",argv[0]);
	noecho();
	curs_set(0);
	start_color();
	keypad(stdscr,TRUE);
	init_pair(1,COLOR_YELLOW,COLOR_BLUE);
	init_pair(2,COLOR_BLACK,COLOR_GREEN);
	{
		win = newwin(LINES-3,COLS,0,0);
		box(win,0,0);
		wbkgd(win,COLOR_PAIR(1));
		mvwprintw(win,0,(COLS - 14)/2,"MY TEXT-EDITOR");
		wrefresh(win);
	}
	scrollok(win,TRUE);
	{
		win_2 = newwin(3,COLS,LINES-3,0);
		box(win_2,0,0);
		wbkgd(win_2,COLOR_PAIR(2));
		mvwprintw(win_2,1,1,"F1 - SAVE | F2 - OPEN | F3 - EDIT | F4 - QUIT");
		wrefresh(win_2);
	}
	while((ch = getch()) != KEY_F(4))
	{
		switch(ch)
		{
			case KEY_F(1):
			save_file(win);
			break;
			case KEY_F(2):
			open_dir(win);
			break;
			case KEY_F(3):
			edit_file(win);
			break;
		}
		noecho();
		curs_set(0);
	}
	delwin(win);
	delwin(win_2);
	endwin();
}