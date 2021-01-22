/*17. Write a program to execute ls -l | wc.---->b. use dup2*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
  int fd[2];
  pipe(fd);
  pid_t pid=fork();
  if(pid==0)						//child
  {
  
  	dup2(fd[1],1);					//duplicating write end, which is stdout and STDOUT is closed 
  	close(fd[0]);					//closing read end
  	execl("/bin/ls","ls","-l",NULL);	//ls writes to STDOUT, which is fd[1] here. This is read by fd[0]
  }
  else if(pid!=0)				     //parent
  {
  	dup2(fd[0],0);					//a copy of fd[0] is made using fd 1, i.e. STDIN and STDIN is closed
  	close(fd[1]);					//closing write end
  	execl("/usr/bin/wc","wc",NULL);    //wc takes an input from STDIN. But now fd[0] is STDIN which reads from fd[1]
  }
  else
  {
  	perror("Error");
  }

	return 0; 
}
 
