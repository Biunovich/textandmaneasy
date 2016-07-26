#include "mylib.h"
void init_windows(WINDOW *win1,WINDOW *win2)
{
	int i = 0,j;
	winlock = TRUE;
	ptr1=ptr2=1;
	sprintf(path1,"/");
	sprintf(path2,"/");
	chdir("/");
	shift1=shift2=0;
	dir = opendir("/");
	struct dirent * entry;
	while ((entry = readdir(dir)) != NULL)
	{
		i++;
	}
	sizedir1 = sizedir2 = i;
	dir1 = calloc(sizeof(char*),i);
	for (j=0;j<sizedir1;j++)
		dir1[j] = calloc(sizeof(char),100);
	dir2 = calloc(sizeof(char*),i);
	for (j=0;j<sizedir2;j++)
		dir2[j] = calloc(sizeof(char),100);
	dir = opendir("/");
	i=0;
	while ((entry = readdir(dir)) != NULL)
	{
		++i;
		if (i<LINES-4){
			mvwprintw(win1,i,2,"%s",entry->d_name);
			mvwprintw(win2,i,2 ,"%s",entry->d_name);
		}
		sprintf(dir1[i-1],"%s",entry->d_name);
		sprintf(dir2[i-1],"%s",entry->d_name);
	}
	wrefresh(win2);
	wrefresh(win1);
}