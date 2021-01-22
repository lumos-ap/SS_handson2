/*14. Write a simple program to create a pipe, write to the pipe, read from pipe and display on the monitor.*/
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main()
{
	int fd[2]; 
	
	/*creates a pipe and returns 2 filde descriptors referring to ends of the pipe
	fd[0] is the read end
	fd[1] is the write end*/
	
	if(pipe(fd)==-1)
	{
		printf("Error! Could not create pipe\n");
	} 
	
	printf("FD[0]: %d\n",fd[0]);
	printf("FD[1]: %d\n",fd[1]);
	
	
	//write end
	char str[]="Using the pipe";
	write(fd[1],str,sizeof(str)-1);
	
	
	//read end
	char *buff=malloc(sizeof(str));
	read(fd[0],buff, sizeof(str));
	
	printf("Read :%s\n",buff);
	
	close(fd[0]);
	close(fd[1]);




}
