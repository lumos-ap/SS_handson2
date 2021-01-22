#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/types.h>
#include<stdio.h>
#include<time.h>



void main()
{
  int msgid;
  key_t key;
  struct msqid_ds mq;

  key=ftok("./26.c",'b');
  msgid=msgget(key,IPC_CREAT|0744);      //getting unique id
  
  if(msgid==-1)
    perror("");
  printf("Message queue id:%d \n",msgid);
  mq.msg_perm.uid=500;
  mq.msg_perm.gid=500;
  mq.msg_perm.mode=0700;

 int ret=msgctl(msgid,IPC_SET,&mq);     //writing the changed permissions to kernel datastructure
  perror("");
  printf("%d\n",ret);

}

