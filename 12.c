/*12. Write a program to create an orphan process. Use kill system call to send SIGKILL signal to the parent process from the child process.*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
int main()
{
  pid_t pid=fork();
  
  
  if(pid==-1)
  	  perror("Error");
  if(pid==0)                   //child process
  {
   	  pid_t ppid=getppid();   //parent pid
    	  printf("Initial parent id: %d\n",ppid);
    	  int k=kill(ppid,SIGKILL);
       if(k==-1)
       {
       	perror("Error");
       	exit(EXIT_FAILURE);
       }
       
       sleep(3);
       printf("New parent id after becoming orphan:%d\n", getppid());
  }
  else                          //parent process
  {
       printf("Parent running...\n");
       sleep(1);
  }

  return 0;
}
