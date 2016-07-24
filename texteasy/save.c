#include "mylib.h"
int len(int lin,int line,WINDOW * win)
{
	int linelen = line;
	while (linelen >= 0 && mvwinch(win,lin,linelen) == ' ')
		linelen--;
	return linelen;
}
void save_file(WINDOW * win)
{
	int fd;
	if ((fd = open(dir,O_RDWR|O_CREAT|O_TRUNC,S_IRWXO|S_IRWXU|S_IRWXG)) == -1)
	{
		perror("Can't open!");
		exit(1);
	}
	int i,j,row,col,n,res;
	char  ch[1];
	getmaxyx(win,row,col);
	for (i=1;i<row-1;i++)
	{
		n = len(i,col-2,win);
		for (j=1;j<n;j++)
		{
			ch[0] = mvwinch(win,i,j);
			if ((res = write(fd,ch,1) == -1))
			{
				perror("Can't write file");
				exit(1);
			}
		}
		ch[0] = '\n';
		write(fd,ch,1);
	}
	close(fd);
}