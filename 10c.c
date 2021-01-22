#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

void handler(int sig)
{
	printf("Caught signal %d (SIGFPE)\n",sig);
	exit(0);
}


int main()
{
	struct sigaction action;
	action.sa_handler=handler; //specify action accociated with signal
	action.sa_flags=0;//modifies behaviour of signal
	
	/*
	int sigaction(int signum, const struct sigaction *act,struct sigaction *oldact);
	signum --> specifies the signal (Cannot be SIGKILL AND SIGSTOP)
	act    --> new action for signum is installed from here
	oldact --> previous action is saved here
	*/
	sigaction(SIGFPE, &action, NULL); 
	
	printf("Generating SIGFPE..\n");
	sleep(1);
	
	int i=10/0;
	
	/*No interrupt generated then handler is not called
	Hence normal executing of program*/
	printf("Normal execution without any error\n");
	return 0;



}
