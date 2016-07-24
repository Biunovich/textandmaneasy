#include "mylib.h"
void change_win(WINDOW * win1,WINDOW * win2)
{
	if (winlock == TRUE)
	{
		ptr2=1;
		wmove(win2,1,1);
		winlock = FALSE;
		chdir(path2);
		wrefresh(win2);
	}
	else if (winlock == FALSE)
	{
		ptr1=1;
		wmove(win1,1,1);
		winlock = TRUE;
		chdir(path1);
		wrefresh(win1);
	}
}