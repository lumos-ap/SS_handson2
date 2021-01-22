#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

void my_handler(int sig)
{
   printf(" I got SIGINT :: number =%d\n",sig); //SIGSEVG=2
   exit(0);
}

int main(void)
{
   int i;
   signal(SIGINT, my_handler);
   printf("Catching SIGINT\n");
   sleep(3); //ctrl+c will cause an interrupt 
   printf("No SIGINT within 3 seconds");
   return 0;

}
