#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <fcntl.h>
#include <unistd.h>
#include<sys/shm.h>

union semun{
    int value;
    struct semid_ds *buf;
    unsigned short int *array;
};


int main() {

    union semun arg;

    int key=ftok("./32c.c", 'a');


    int semid = semget(key, 1, 0);
    if(semid == -1){
    	semid = semget(key, 1, IPC_CREAT|0644);    
        arg.value = 2;
        semctl(semid, 0, SETVAL, arg);
    }


    struct sembuf buf = {0,-1,0};
    
    printf("Before Entering into the critical section..\n");
    if (semop(semid, &buf, 1) == -1) {
        perror("semop");
        exit(0);
    }
    int shmid = shmget(key, 1024, 0);
    if(shmid == -1){
        shmid = shmget(key, 1024, IPC_CREAT|0744);    
    }
    printf("Inside the critical section\n");

    char *ptr = shmat(shmid, (void *)0, 0);

    printf("Enter data to write into shared memory: ");
    scanf(" %[^\n]", ptr);
    getchar();
    buf.sem_op=1;
     printf("Press enter to exit the lock.\n");
	getchar();
    semop(semid, &buf, 1);

   
	return 0;	
    
}
