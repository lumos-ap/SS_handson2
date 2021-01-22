#include<stdio.h>
#include<sys/time.h>
#include<sys/resource.h>
#include<string.h>
int main()
{
	struct rlimit r;
	struct rlimit r2;
	getrlimit(RLIMIT_NOFILE,&r);
	printf("\nDefault values of no. of file descriptors :%ld\n", r.rlim_cur);
	r.rlim_cur=4;
	setrlimit(RLIMIT_NOFILE,&r);
	getrlimit(RLIMIT_NOFILE, &r2);
	printf("\nValues of no. of file descriptors after changing:%ld\n", r2.rlim_cur);
	return 0;

}
