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

   fd = open("fifo20", O_RDONLY);
   if(fd==-1)
   {
     perror("Error");
     exit(EXIT_FAILURE);
   }
   read(fd,buff,sizeof(buff)-1); //reading from fifo
   printf("Read from pipe: %s\n",buff);
   close(fd);
}
