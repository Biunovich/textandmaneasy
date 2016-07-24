#include "mylib.h"
void open_dir(WINDOW * win)
{
	int row,col,fd;
	getmaxyx(win,row,col);
	start_color();
	init_pair(3,COLOR_BLACK,COLOR_BLUE);
	WINDOW * local_win;
	delwin(win);
	refresh();
	{
		win = newwin(LINES-3,COLS,0,0);
		box(win,0,0);
		wbkgd(win,COLOR_PAIR(1));
		mvwprintw(win,0,(COLS - 14)/2,"MY TEXT-EDITOR");
		wrefresh(win);
	}
	local_win = subwin(win,4,COLS/3,row/2,(col - COLS/3)/2);
	box(local_win,0,0);
	wbkgd(local_win,COLOR_PAIR(3));
	getmaxyx(win,row,col);
	mvwprintw(local_win,1,2,"TYPE IN FILE LOCATION:");
	wmove(local_win,2,2);
	wrefresh(local_win);
	wrefresh(win);
	echo();
	curs_set(1);
	sprintf(dir,"%s",argum);
	wclear(local_win);
	werase(local_win);
	wrefresh(local_win);
	{
		int ptr=1,ptrcol=1;
		long int res;
		char ch;
		if ((fd = open(dir,O_RDWR|O_CREAT,S_IRWXO|S_IRWXU|S_IRWXG)) == -1)
		{
			perror("Can't open!");
			exit(1);
		}
		while((res = read(fd,&ch,1)) > 0)
		{
			if (ch == '\n')
			{
				ptrcol++;
				ptr = 1;
				continue;
			}
			mvwprintw(win,ptrcol,ptr++,"%c",ch);
		}
		wrefresh(win);
	}
	close(fd);
	delwin(local_win);
}