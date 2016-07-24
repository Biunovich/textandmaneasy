obj = curses.o edit.o open.o save.o
curses : $(obj) mylib.h
		cc -o curses $(obj) -lncurses
$(obj) : mylib.h 
