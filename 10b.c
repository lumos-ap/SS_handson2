#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

void handler(int sig)
{
	printf("\nCaught signal %d\n",sig);
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
	sigaction(SIGINT, &action, NULL); 
	
	printf("Generate Interrupt!\n");
	/*Waits for interrupt for 5 seconds*/
	sleep(5);
	
	/*No interrupt generated then handler is not called
	Hence normal executing of program*/
	printf("No interrupt generated within 5 seconds\n");
	return 0;



}
