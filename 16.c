/*16. Write a program to send and receive data from parent to child vice versa. Use two way communication.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
int main()
{
  
  int fd1[2], fd2[2];
  pipe(fd1);  								//child: writes parent: reads
  pipe(fd2);								//child: reads  parent: writes
  
  char writeb[50];
  char readb[50];
  
  
  
  pid_t pid=fork();
  if(pid==-1)
  	  perror("Error");
  if(pid!=0)                   				//parent process
  {
  	
  	close(fd1[1]);					 		//closing write end for parent
  	
  	read(fd1[0],readb,sizeof(writeb));			//reading from child
     printf("Reading message from child: ");
     printf("%s \n\n",readb);
     
     close(fd2[0]);							//closing read end for parent 
  	printf("Enter a message for child:");
  	scanf("%[^\n]",writeb); 	
  	write(fd2[1],writeb,sizeof(writeb)); 
 
  }
  else                          				//child process
  {
  	close(fd1[0]);							//closing read end for child
  	printf("Enter a message for parent:");		
  	scanf("%[^\n]",writeb); 	
  	write(fd1[1],writeb,sizeof(writeb));
  	 
  	close(fd2[1]); 						//closing write end for child
     read(fd2[0],readb,sizeof(writeb));
     printf("Reading message from parent:");
     printf("%s \n\n",readb);
  }

  return 0;
}
