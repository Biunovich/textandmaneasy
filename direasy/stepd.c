#include "mylib.h"
void scrol(WINDOW * win,int *shift ,int *ptr,char ** dir_o,int sizedir)
{
	int i;
	if ((*ptr<(LINES -5 )) && (*ptr + *shift) < sizedir)
	{
		wmove(win,++(*ptr),1);
		wrefresh(win);
	}
	else if (*ptr>=LINES -5)
	{
		wclear(win);
		box(win,0,0);
		*shift += 1;
		*ptr = 1;
		for (i=1;i<LINES-4;i++)
		{
			if (i<sizedir-1)
				mvwprintw(win,i,2,"%s",dir_o[i+*shift-1]);
		}
		wmove(win,1,1);
		wrefresh(win);
	}
	else if ((*ptr + *shift) >= sizedir)
	{
		wclear(win);
		box(win,0,0);
		*shift = 0;
		*ptr = 1;
		for (i=1;i<LINES-4;i++)
		{
			if (i<sizedir+1)
				mvwprintw(win,i,2,"%s",dir_o[i+*shift-1]);
		}
		wmove(win,1,1);
		wrefresh(win);
	}
}
void step_down(WINDOW *win1,WINDOW * win2)
{
	if (winlock == TRUE)
		scrol(win1,&shift1,&ptr1,dir1,sizedir1);
	else if (winlock == FALSE)
		scrol(win2,&shift2,&ptr2,dir2,sizedir2);
}