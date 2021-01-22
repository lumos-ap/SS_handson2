/*7. Write a simple program to create three thread ids*/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
void * connection_handler(void *i)
{
	int threadnum=*(int*)i;
	printf("Thread number: %d\n", threadnum);
	printf("Thread ID: %ld\n\n", pthread_self());
	return 0;
}
void main()
{
	pthread_t thread;
	for(int i=0;i<3;i++)
	{
		
		int r=pthread_create(&thread, NULL, connection_handler,(void*)&i);
		
		if(r<0)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	
	}
	pthread_exit(NULL);

}
