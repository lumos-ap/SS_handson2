#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
void main()
{
   int fd;
   char buff[1024];

   printf("Enter a message:");
   scanf("%[^\n]",buff);

   mkfifo("fifo20",0744); //creates fifo if it doesnt exist, otherwise returns error

   fd = open("fifo20", O_WRONLY);
   if(fd==-1)
   {
     perror("Error");
     exit(EXIT_FAILURE);
   }
   write(fd,buff,sizeof(buff)-1); //writing to fifo which will be then read by another process
   printf("Message written to fifo\n");
   close(fd);
}
