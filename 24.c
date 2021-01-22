#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>

int main()
{
  int msgid;
  key_t key;
  key=ftok("./24.c",'a'); //convert  a pathname and a project identifier to a System V IPC key
 
  msgid=msgget(key,IPC_CREAT|IPC_EXCL|0744);    //if  message queue already exsists, returns error
  if(msgid==-1)
  {	
  	perror("");
  	
  }
  
  printf("Key=%d \nKey in hex =0x%0x\nMessage queue id=%d\n",key,key,msgid);
  return 0;




}
