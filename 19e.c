#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
void main()
{
  /*int mkfifo(const char *pathname, mode_t mode);
    pathname --> pathname and name of fifo
    mode     --> permissions of fifo */
    int fifo=mkfifo("fifo19e",0777);
    if(fifo==-1)
      perror("Error");
    else
      printf("mkfifo returned: %d\nSuccess\n",fifo);

}
