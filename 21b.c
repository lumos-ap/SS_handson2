#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
void main()
{
   int fdr,fdw;
   char readbuff[1024];
   char writebuff[1024];

   fdr = open("fifo21a", O_RDONLY); 	//to read message from pipe
   if(fdr==-1)
   {
     perror("Error");
     exit(EXIT_FAILURE);
   }
   
   read(fdr,readbuff,sizeof(readbuff)-1); //reading from fifo (from program 1)
   printf("Message from program 1: %s\n",readbuff);
   
   
   fdw = open("fifo21b", O_WRONLY);		//to write message to pipe
   if(fdw==-1)
   {
     perror("Error");
     exit(EXIT_FAILURE);
   }
   
   printf("Enter a message to program1: ");
   scanf("%[^\n]",writebuff);
   
   write(fdw,writebuff,sizeof(writebuff)-1); //writing to fifo (for program 1)
  
   
   
   close(fdr);
   close(fdw);
   
}
