#include<sys/time.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void signal_handler()
{
	printf("SIGPROF is caught \n");
	printf("Stopped timer \n");
	exit(0);
}

int main()
{
	signal(SIGPROF, signal_handler); //when it recieves the signal, it will call the second argument thats a function
	struct timeval tv={10,10}; //starting point
	struct timeval tv1={0,0};  //expiration point
	
	//interval for periodic timer
	struct itimerval value; //sends the signal
	value.it_value=tv;
	value.it_interval=tv1;
	
	int ret;
	printf("Start timer\n");
	ret=setitimer(ITIMER_PROF, &value, NULL); //counts down against total time (both cpu and user
	sleep(5);
	while(1){}
	return 0;

}
