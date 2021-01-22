#include<sys/time.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void signal_handler()
{
	printf("SIGALRM is caught \n");
	printf("Stopped timer \n");
	exit(0);

}

int main()
{
	signal(SIGALRM, signal_handler);
	struct timeval tv={10,10}; //starting point
	struct timeval tv1={0,0};  //expiration point
	
	//interval for periodic timer
	struct itimerval value; //sends the signal
	value.it_value=tv;
	value.it_interval=tv1;
	
	int ret;
	printf("Start timer\n");
	ret=setitimer(ITIMER_REAL, &value, NULL); //counts down in real time and delivers SIGALRM upon expiration
	sleep(5);
	while(1){}
	return 0;

}
