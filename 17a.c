/*17. Write a program to execute ls -l | wc.---->a. use dup*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
  int fd[2];
  pipe(fd);
  pid_t pid=fork();
  if(pid==0)					//child
  {
  	close(1);					//closing STDOUT so that ls-l does not write anything 
  	dup(fd[1]);				//a copy of fd[1] is made using least available fd, i.e. STDOUT 
  	close(fd[0]);				//closing read end
  	execl("/bin/ls","ls","-l",NULL); //ls writes to STDOUT, which is fd[1] here. This is read by fd[0]
  }
  else if(pid!=0)				//parent
  {
  	close(0);					//closing STDIN 
  	dup(fd[0]);				//a copy of fd[0] is made using least available fd, i.e. STDIN
  	close(fd[1]);				//closing write end
  	execl("/usr/bin/wc","wc",NULL);  //wc takes an input from STDIN. But now fd[0] is STDIN which reads from fd[1]
  }
  else
  {
  	perror("Error");
  }

	return 0; 
}
 
