/*6. Write a simple program to create three threads*/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
void * connection_handler(void *i) //starts routine
{
	printf("Inside Thread \n");
	return 0;
}
void main()
{
	pthread_t thread;
	for(int i=0;i<3;i++)
	{
		/*int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);
		*/
		int r=pthread_create(&thread, NULL, connection_handler,NULL);
		
		if(r<0)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
		
		printf("Running thread %d\n",i);
	
	}
	pthread_exit(NULL);

}
