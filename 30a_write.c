#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<stdio.h>

void main()
{
  int shmid,key;
  char* data;
  key=ftok("./30a_write.c",'a');
  shmid=shmget(key,1024,IPC_CREAT|0744);
  data=shmat(shmid,0,0);
  printf("Enter text:");
  scanf("%[^\n]",data);

}
