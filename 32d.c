#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <time.h>

int main(int agrc, int const argv[]){
	
	key_t sem_key = ftok("./32d.c", 'a');                     // Generate a unique key
	
	
	int id = semget(sem_key, 1, IPC_CREAT | IPC_EXCL | 0744);    //getting a new semaphore id
	int i = semctl(id, 0, SETVAL, 1);
	
	printf("SEM ID : %d\n", id);
	int ret = semctl(id, 0, IPC_RMID, 1);			//removing semaphore
	if(ret == -1)
		perror("Error");
	else
		printf("Semaphore removed\n");
	
}
