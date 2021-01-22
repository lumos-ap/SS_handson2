#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/types.h>
#include<stdio.h>
#include<time.h>



void main()
{
  int msgid;
  key_t key;
 // struct msqid_ds mq;

  key=ftok("./26.c",'b');
  msgid=msgget(key,IPC_CREAT|0744);      //getting unique id


  int ret=msgctl(msgid,IPC_RMID,0);  //removing message queue
  if(ret==-1)
	perror("");
  else
        printf("SUCCESS::%d\n",ret);

}

