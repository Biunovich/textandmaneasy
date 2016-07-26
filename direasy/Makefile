obj = fileman.o change.o stepd.o chdir.o init_win.o copy.c
fileman : $(obj) mylib.h
		cc -o fileman $(obj) -lncurses -lpthread
$(obj) : mylib.h 
