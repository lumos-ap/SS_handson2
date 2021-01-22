#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/time.h>
#include<time.h>

int main()
{
  int msgid;
  struct msqid_ds msg;
  struct ipc_perm msg_perm;
  key_t key;
  
  key=ftok("./25.c",'a');  //generating key
  msgid=msgget(key,IPC_CREAT|0744); //getting a system v message queue identifier associated with key
  
  if(msgid==-1)
  {	
  	perror("");	
  }
  
  msgctl(msgid,IPC_STAT,&msg); //copying information from kernel data structure associated with msgid into the msqid_ds structure "msg"
  
  msg_perm=msg.msg_perm;
  
  printf("Acess permission =%d\n",msg_perm.mode & 0777);
  printf("Owner UID =%d\n",msg_perm.uid);
  printf("Owner GID=%d\n",msg_perm.gid);
  printf("Creator UID =%d\n",msg_perm.cuid);
  printf("Creator GID=%d\n",msg_perm.cgid);
  printf("Time of last message sent=%s",ctime(&msg.msg_stime));
  printf("Time of last message recieved=%s",ctime(&msg.msg_rtime));
  printf("Time of last change in queue=%s",ctime(&msg.msg_ctime));
  printf("Size of the queue =%ld\n",msg.__msg_cbytes);
  printf("Number of messages in queue =%ld\n",msg.msg_qnum);
  printf("Maximum number of bytes allowed =%ld\n",msg.msg_qbytes);
  printf("PID of message sent=%d\n",msg.msg_lspid);
  printf("PID of message recieved =%d\n",msg.msg_lrpid);
  



  return 0;
}
