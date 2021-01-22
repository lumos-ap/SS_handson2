#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<stdio.h>

void main()
{
  int shmid, key, detach;
  char *data;
  key=ftok("./30a_write.c",'a');  //creating unique key
  shmid=shmget(key,1024,IPC_CREAT|0744);
  data=shmat(shmid,0,0);  //returns address of attached shared memory
  detach=shmdt(data);
  printf("Detach value:%d\n",detach);

}
