/*13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program will send the signal (using kill system call). Find out whether the first program is able to catch the signal or not.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void my_handler(int sig)
{
   printf("SIGSTOP caught :: number =%d\n",sig); //SIGFPE=8
   exit(0);
}

int main(void)
{
   
   signal(SIGSTOP, my_handler);
   printf("My PID: %d\n",getpid());

   sleep(1);
   printf("Catching SIGFPE....\n");
   sleep(1);
   printf("Waiting for other process to call kill()...\n");
   
   while (1);
   
   return 0;

}
