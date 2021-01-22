#include<stdio.h>
#include<sys/time.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

unsigned long long rdtsc(void)
{
	unsigned long long dst;
	__asm__ __volatile("rdtsc" : "=A"(dst));
	return dst;
}

int main()
{
	long long int start, end;
	start=rdtsc();
	int i;
	printf("Initial value=%llu\n",start);
	for(i=0;i<100;i++)
	{
		getppid();
	}
	end=rdtsc();
	printf("End Value= %llu\n",end);
	end=end-start;
	printf("Cycles taken= %llu\n",end);
	return 0;
}
