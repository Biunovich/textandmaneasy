obj = fileman.o change.o stepd.o chdir.o init_win.o
fileman : $(obj) mylib.h
		cc -o fileman $(obj) -lncurses
$(obj) : mylib.h 