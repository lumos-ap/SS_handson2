#include<sys/types.h>
#include<sys/ipc.h>
#include<stdio.h>
#include <sys/sem.h>
#include <errno.h>

// arg for semctl system calls. 
union semun
{
  int val;			  // value for SETVAL 
  struct semid_ds *buf;   // buffer for IPC_STAT & IPC_SET
  ushort *array; 		 // array for GETALL & SETALL 
};

void main()
{
  union semun arg;
  int semid, key;
  
  key=ftok("./31b.c",'a');				//unique key value
  semid=semget(key,1,IPC_CREAT|0744); 		// returns system v semaphore set identifier associated with key
  arg.val=3; 							//1= binary, more than 1 for counting semaphore
  
    /* Def:----> int semctl(int semid, int semnum, int cmd, ...);*/
  
  int ret=semctl(semid, 0, SETVAL, arg); 	//sets the value of SEMVAL to arg.val for semid 
  if(ret==-1)
  perror("Error");
  else
  printf("Counting Semaphore Created. \n");

}
