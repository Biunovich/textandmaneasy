#include "mylib.h"
void main(void)
{
	int fd,count,i;
	long lseekres,res;
	char arr[15] = "Hellow world!",ch;
	count = strlen(arr);
	if ((fd = open("./file.txt",O_RDWR|O_CREAT,S_IRWXO|S_IRWXU|S_IRWXG)) == -1)
	{
		perror("Can't open!");
		exit(1);
	}
	for (i=0;i>=(-count);i--){
		if ((lseekres = lseek(fd,i,SEEK_END)) == -1)
		{
			perror("Can't set cursor");
			exit(1);
		}
		if ((res = read(fd,&ch,1)) == -1)
		{
			perror("Can't write");
			exit(1);
		}
		printf("%c",ch);
	}
	printf("\n");

}