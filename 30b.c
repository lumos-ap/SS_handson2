#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<stdio.h>

void main()
{
  int shmid, key;
  char *data;
  key=ftok("./30a_write.c",'a');
  shmid=shmget(key,1024,0);
  data=shmat(shmid,(void *)0,SHM_RDONLY);
  printf("Text from shared memory:%s\n",data);
  printf("Try to Enter Data:\n");
  scanf("%[^\n]",data);




}
