#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>	
#include <ncurses.h>
char dir[100];
char argum[30];
void save_file(WINDOW * win);
void open_dir(WINDOW * win);
void edit_file(WINDOW * win);