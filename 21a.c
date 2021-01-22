#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
void main()
{
   int fdr, fdw;
   char readbuff[1024];
   char writebuff[1024];

   
   
   fdw = open("fifo21a", O_WRONLY);		//to write message to pipe
   if(fdw==-1)
   {
     perror("Error");
     exit(EXIT_FAILURE);
   }
   
   printf("Enter a message to program 2: ");
   scanf("%[^\n]",writebuff);
   
   write(fdw,writebuff,sizeof(writebuff)-1); //writing to fifo (for program 2)
   
   
   fdr = open("fifo21b", O_RDONLY); 	//to read message from pipe
   if(fdr==-1)
   {
     perror("Error");
     exit(EXIT_FAILURE);
   }
   
   read(fdr,readbuff,sizeof(readbuff)-1); //reading from fifo (from program 2)
   printf("Message from program 2: %s\n",readbuff);
   
   close(fdr);
   close(fdw);
}
