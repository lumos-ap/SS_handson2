#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<stdio.h>

void main()
{
  int shmid, key,r;
  char *data;
  key=ftok("./30a_write.c",'a');
  shmid=shmget(key,1024,IPC_CREAT|0744);
  r=shmctl(shmid,IPC_RMID,NULL);
  printf("Remove value:%d\n",r);

}
