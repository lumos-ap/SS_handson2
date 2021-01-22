#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

void my_handler(int sig)
{
   printf("SIGFPE :: number =%d\n",sig); //SIGFPE=8
   exit(0);
}

int main(void)
{
   int i=1;
   signal(SIGFPE, my_handler);
   printf("Catching SIGFPE\n");
   i=i/0;
   return 0;

}
