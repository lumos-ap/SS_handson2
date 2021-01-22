#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<sys/resource.h>
#include<sys/time.h>
#include<unistd.h>

int main()
{
	struct rlimit limits;
	char s1[18][20]={"RLIMIT_CPU", "RLIMIT_CORE", "RLIMIT_FSIZE","RLIMIT_NOFILE","RLIMIT_NPROC","RLIMIT_AS","RLIMIT_DATA","RLIMIT_LOCKS","RLIMIT_MEMLOCK","RLIMIT_MSGQUEUE", "RLIMIT_NICE","RLIMIT_NOFILE","RLIMIT_NPROC","RLIMIT_RSS","RLIMIT_RTPRIO","RLIMIT_RTTIME","RLIMIT_SIGPENDING","RLIMIT_STACK"};
	int s[18]={RLIMIT_CPU, RLIMIT_CORE,RLIMIT_FSIZE,RLIMIT_NOFILE,RLIMIT_NPROC,RLIMIT_AS,RLIMIT_DATA,RLIMIT_LOCKS,RLIMIT_MEMLOCK,RLIMIT_MSGQUEUE, RLIMIT_NICE,RLIMIT_NOFILE,RLIMIT_NPROC,RLIMIT_RSS,RLIMIT_RTPRIO,RLIMIT_RTTIME,RLIMIT_SIGPENDING,RLIMIT_STACK};
	for(int i=0;i<18;i++)
	{
	getrlimit(s[i],&limits);
	printf("%s :-\nsoftlimit: %lu\nHard limit: %lu\n\n",s1[i],limits.rlim_cur,limits.rlim_max);
	
	}




}
