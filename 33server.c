#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
void main()
{
	struct sockaddr_in serverad,clientad;
	int sfd,nsd,clientLen;
	char buff[50];
	
	
	/*Domain: AF_INET (IPv4 internet protocols)
	  Type: SOCK_STREAM (Sequenced, reliable two way connectionb based byte streams)
	  creating tcp socket, returns socket file descriptor*/
	  
	sfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);  
	
	serverad.sin_family=AF_INET;
	serverad.sin_addr.s_addr=INADDR_ANY;
	serverad.sin_port=htons(5555);  						//convers 5555 from host byte order to network byte order
	
	bind(sfd,(struct sockaddr *)&serverad,sizeof(serverad));    //binds a name to socket
	
	listen(sfd,2); 									//coverts socket to passive, used to accept connections

	printf("Waiting for client...\n");
	while(1)
	{
		clientLen=sizeof(clientad);
		nsd=accept(sfd,(struct sockaddr *)&clientad,&clientLen);  //accepting connection, returns fd of accepted socket
		printf(".\n");
		write(1,"Connected to client...\n",sizeof("Connected to client...\n"));
		write(nsd,"Connected to server...\n",sizeof("Connected to server...\n")); //message from server to client
		read(nsd, buff,sizeof(buff));  //reading message from client
		printf("%s\n",buff);
		close(nsd);
		write(1,"Waiting for the client...\n",sizeof("Waiting for the client...\n")); //waiting for new client
	}
	
	close(sfd);

}
