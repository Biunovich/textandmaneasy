#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>	
#include <ncurses.h>
DIR * dir;
char ** dir1,**dir2,path1[100],path2[100];
int sizedir1, sizedir2,ptr1,shift1,ptr2,shift2;
bool winlock;
void init_windows(WINDOW * win1,WINDOW * win2);
void change_win(WINDOW * win1,WINDOW * win2);
void step_down(WINDOW *win1,WINDOW * win2);
void change_dir(WINDOW *win1,WINDOW * win2);
void copy_file(WINDOW *win1,WINDOW *win2);