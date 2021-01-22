#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/types.h>
#include<stdio.h>
#include<time.h>

struct msg
{
  long int mtype;
  char mtext[1024];
}myq;

void main()
{
  int msgid;
  key_t key;

  key=ftok("./26.c",'b');
  msgid=msgget(key,IPC_CREAT|0744);      //getting unique id
  printf("Enter message type:");		//msgtype:0  -> 1st message in queue is read
  scanf("%ld",&myq.mtype);			//msgtyppe>0 -> 1st message in queue of given type is read


  int r=msgrcv(msgid,&myq,sizeof(myq.mtext),myq.mtype,IPC_NOWAIT); //receiving message from System V message queue. IPC_NOWAIT: will not wait if no message is in queue
  printf("Message: %s\n",myq.mtext);

}

