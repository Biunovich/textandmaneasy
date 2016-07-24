#include "mylib.h"
void edit_file(WINDOW *win)
{
	int ch,y=1,x=1,maxx,maxy;
	getmaxyx(win,maxy,maxx);
	curs_set(1);
	wmove(win,y,x);
	wrefresh(win);
	while((ch = getch()) != KEY_F(4))
	{
		switch(ch)
		{
			case KEY_UP:
			if (y>1)
				wmove(win,--y,x);
			break;
			case KEY_DOWN:
			if (y<maxy-2)
				wmove(win,++y,x);
			break;
			case KEY_LEFT:
			if (x>1)
				wmove(win,y,--x);
			break;
			case KEY_RIGHT:
			if (x<maxx-2)
				wmove(win,y,++x);
			break;
			default:
			if (ch == KEY_BACKSPACE && x>1)
			{
				mvwprintw(win,y,--x,"%c",' ');
				wmove(win,y,x);
				break;
			}
			if (x<maxx-2 && ch != KEY_BACKSPACE)
			{
				mvwinsch(win,y,x++,ch);
				box(win,0,0);
			}
			break;
		}
		wrefresh(win);
	}
}