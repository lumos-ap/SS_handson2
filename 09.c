#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int main()
{

	signal(SIGINT, SIG_IGN);
	printf("Ignoring SIGINT\n");
	sleep(5);
	printf("No SIGINT within 5 sec\n\n");
	
	signal(SIGINT, SIG_DFL);
	printf("Default action for SIGINT\n");
	sleep(5);
	printf("No SIGINT within 5 sec \n\n");
	return 0;


}
