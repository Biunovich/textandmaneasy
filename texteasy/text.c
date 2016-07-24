#include "mylib.h"
void main (void)
{
	int fd;
	long int res,read_bytes;
	char arr[15] = "Hellow world!",ch;
	if ((fd = open("./file.txt",O_RDWR|O_CREAT,S_IRWXO|S_IRWXU|S_IRWXG)) == -1)
	{
		perror("Can't open!");
		exit(1);
	}
	if ((res = write(fd,arr,strlen(arr))) == -1)
	{
		perror("Can't write file");
		exit(1);
	}
	if (res != strlen(arr))
	{
		perror("Can't write!");
		exit(1);
	}
    if (close(fd) == -1)
    {
    	perror("Can't close!");
    	exit(1);
    }
    if ((fd = open("./file.txt",O_RDWR)) == -1)
	{
		perror("Can't open!");
		exit(1);
	}
	while((read_bytes = read(fd,&ch,1)) > 0)
		printf("%c",ch);
	printf("\n");
    if (close(fd) == -1)
    {
    	perror("Can't close!");
    	exit(1);
    }
}
