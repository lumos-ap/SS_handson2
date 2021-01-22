/*18. Write a program to find out total number of directories on the pwd. execute ls -l | grep ^d | wc ? Use only dup*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

void main()
{
	int fd1[2];		//read output of ls and pass to grep 
	int fd2[2];		//read output of grep and pass to wc
	pipe(fd1);
	pipe(fd2);
	
	if(!fork())			//child1
	{
		
		dup2(fd1[1],1);	//closing STDOUT so that nothing is printed and creating a copy of fd1[1] as '1'
		close(fd1[0]);		//any pipe end that is not being used is closed
		close(fd2[0]);
		close(fd2[1]);
		execl("/usr/bin/ls","ls","-l",NULL); //ls writes to STDOUT, which is fd1[1] here. This is read by fd1[0]
	
	}
	else					
	{
		if(!fork())		//child2
		{	
			
			dup2(fd2[1],1);	//closing STDOUT so that nothing is printed and creating a copy of fd2[1] as '1'
			close(fd2[0]);
			dup2(fd1[0],0);	//closing STDIN so that grep does not get input from stdin and creating copy of fd1[0] as '0'
			
			close(fd1[1]);
			execl("/usr/bin/grep","grep","^d",NULL);
		
		}
		else				//parent
		{
			dup2(fd2[0],0);
			close(fd2[1]);
			close(fd1[0]);
			close(fd1[1]);
			execl("/usr/bin/wc","wc",NULL);
			
		}
	
	}

}
