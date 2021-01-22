#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>



int main()
{
	struct sigaction action;
	action.sa_handler=SIG_IGN; //on catching a signal, it will be ignored
	action.sa_flags=SA_RESTART; //makes system call restartable across signals
	
	
	
	sigaction(SIGINT, &action, NULL); 
	
	printf("Generate Interrupt\n");
	/*Waits for interrupt for 5 seconds*/
	sleep(5);
	printf("\nInterrupt Ignored\n");
	
	
	
	action.sa_handler=SIG_DFL; //default action 
	sigaction(SIGINT, &action, NULL);
	
	
	printf("Generate Interrupt\n");
	/*Waits for interrupt for 5 seconds*/
	sleep(5);
	printf("No interrupt generated within 5 seconds\n");
	return 0;



}
