#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main()
{
char buf[100];
int k;
int sockid,newsocket;
struct sockaddr_in server,client;
socklen_t len;

memset(&server,0,sizeof(server));
memset(&client,0,sizeof(client));

sockid = socket(AF_INET,SOCK_STREAM,0);

if(sockid ==-1)
{
printf("Error in socket creation");
exit(1);
}
server.sin_family=AF_INET;
server.sin_addr.s_addr = inet_addr("127.0.0.1");
server.sin_port=3002;

k = bind(sockid,(struct sockaddr*)&server,sizeof(server));
if(k==-1){
printf("Error in binding");
exit(1);
}

k=listen(sockid,20);
if(k==-1)
{
printf("Error in listening");
exit(1);
}
len = sizeof(client);//VERY IMPORTANT

newsocket = accept(sockid,(struct sockaddr*)&client,&len);//VERY //IMPORTANT
if(newsocket==-1)
{
printf("Error in temporary socket creation");
exit(1);
}
while(1)
{
	k=recv(newsocket,buf,100,0);
	if(k==-1)
	{
		printf("Error in receiving");
		exit(1);
	}
	printf("Message got from client is : %s",buf);
	printf("\nEnter data to be send to client: ");
	fgets(buf,100,stdin);
	if(strncmp(buf,"end",3)==0)
		break;
	k=send(newsocket,buf,100,0);
	if(k==-1)
		{	
			printf("Error in sending");
			exit(1);
		}
}
close(newsocket);
exit(0);
return 0;
}
