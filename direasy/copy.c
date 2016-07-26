#include "mylib.h"
void *copy_thread()
{
	WINDOW * bar = newwin(LINES/5,COLS/3,LINES/2,(COLS - COLS/3)/2);
	box(bar,0,0);
	wrefresh(bar);
	int fd1, fd2,i, progress=0;
	struct stat buf;
	char *des, *src,pa1[100];
	chdir(path1);
	sprintf(pa1,"./%s",dir1[ptr1 + shift1-1]);
	stat(dir1[ptr1 + shift1-1],&buf);
	fd1 = open(pa1, O_RDONLY);
	chdir(path2);
	fd2 = open(pa1,O_CREAT|O_RDWR, S_IRWXU | S_IRWXG | S_IROTH);
	ftruncate(fd2,buf.st_size);
    src = mmap(NULL,buf.st_size,PROT_READ,MAP_SHARED,fd1,0);
	des = mmap(NULL,buf.st_size,PROT_READ | PROT_WRITE,MAP_SHARED,fd2,0);
	for (i=0;i<buf.st_size;i++)
	{
	    des[i] = src[i];
	 	progress = (i * 100)/buf.st_size;
	 	mvwprintw(bar,2,(COLS/3 - 5)/2,"%d percent",progress);
	 	wrefresh(bar);
	}
	wclear(bar);
	wrefresh(bar);
	munmap(src,buf.st_size);
	munmap(des,buf.st_size);
	close(fd1);
	close(fd2);
}
void copy_file(WINDOW *win1,WINDOW *win2)
{
	pthread_t pthread;
	struct stat buf;
	chdir(path1);
	stat(dir1[ptr1+shift1-1],&buf);
	if (S_ISREG(buf.st_mode) == FALSE)
		return;
	pthread_create(&pthread,NULL,copy_thread,NULL);
	pthread_join(pthread,0);
	wclear(win1);
	wclear(win2);
	box(win1,0,0);
	box(win2,0,0);
	init_windows(win1,win2);
	wmove(win1,1,1);
	wrefresh(win1);
}