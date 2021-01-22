#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/time.h>
#include<stdlib.h>
void main()
{
   int fd;
   char buff[1024];

   fd = open("fifo22", O_RDONLY|O_NONBLOCK);
   if(fd==-1)
   {
     perror("Error");
     exit(EXIT_FAILURE);
   }
   
   fd_set rfds;
   struct timeval tv;
   int retval;
   
   /*clear set*/  
  FD_ZERO(&rfds);
  
  /*add pipe fd to set*/
  FD_SET(fd, &rfds);

  /*Setting time= 10s */
  tv.tv_sec = 10;
  tv.tv_usec = 0;
  
  /*null set for writefd and exceptfds 
  readfd check if characters are available for reading
  ndf = fd+1 (set :to highest value of fd in the fdset +1)*/
  
  retval = select(fd+1, &rfds, NULL, NULL, &tv); //returns total no of fds
  
  if (retval == -1)
      perror("select()");
  else if (retval)
  { 
        printf("Data is available now.\n");
  }
  else
      {  
         printf("No data within ten seconds.\n");
         exit(0);
      }
   
   read(fd,buff,sizeof(buff)-1); //reading from fifo
   printf("Read from pipe: %s\n",buff);
   close(fd);
}
