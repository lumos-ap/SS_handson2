#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

void my_handler(int sig)
{
   printf("SIGALRM :: number =%d\n",sig); //SIGALRM=14
   exit(0);
}

int main(void)
{
   int i;
   signal(SIGALRM, my_handler);
   printf("Catching SIGALRM\n");
   alarm(1);
   pause(); //waits for signal
    return 0;

}
