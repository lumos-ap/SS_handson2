/*15. Write a simple program to send some data from parent to the child process.*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
int main()
{
  
  int fd[2];
  pipe(fd);
  printf("fd[0]: %d\n",fd[0]);
  printf("fd[1]: %d\n",fd[1]);
  
  char rbuff[20], wbuff[20];
  
  
  pid_t pid=fork();
  if(pid==-1)
  	  perror("Error");
  if(pid!=0)                   			//parent process
  {
  	close(fd[0]);						//reading end closed for parent
  	printf("Enter a message for child:");
  	scanf("%[^\n]",rbuff); 	
  	write(fd[1],rbuff,sizeof(rbuff)); 
 
  }
  else                          			//child process
  {
  	close(fd[1]);						//writing end closed for child
     read(fd[0],wbuff,sizeof(rbuff));
     printf("\nReading message from parent:\n");
     printf("%s\n",wbuff);
  }
  
  close(fd[0]);
  close(fd[1]);

  return 0;
}
