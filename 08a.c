#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

void my_handler(int sig)
{
   printf("SIGSEGV :: number =%d\n",sig); //SIGSEVG=11
   exit(0);
}

int main(void)
{
   int i;
   signal(SIGSEGV, my_handler);
   printf("Catching SIGSEGV\n");
   scanf("%d",i); // using a memory that doesnt exist
   return 0;

}
