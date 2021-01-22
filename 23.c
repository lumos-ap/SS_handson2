#include<unistd.h>
#include<stdio.h>

void main()
{
  long maxfile=sysconf(_SC_OPEN_MAX);
  printf("Maximum number of files that can be opened within a process: %ld\n",maxfile);

  long pipesize=pathconf("fifo23",_PC_PIPE_BUF);
  printf("Size of pipe fifo23: %ld", pipesize);


}
