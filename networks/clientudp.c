#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
int main(){
  int clientSocket, portNum, nBytes;
  char buffer[1024];
  struct sockaddr_in server;
  socklen_t addr_size;
  memset(&server,0,sizeof(server));
  clientSocket = socket(PF_INET, SOCK_DGRAM, 0);
  server.sin_family = AF_INET;
  server.sin_port = htons(7891);
  server.sin_addr.s_addr = inet_addr("127.0.0.1");  

  addr_size = sizeof server;

  while(1){
    printf("Type a sentence to send to server:\n");
    fgets(buffer,1024,stdin);
    printf("You typed: %s",buffer);

    nBytes = strlen(buffer) + 1;
    
    sendto(clientSocket,buffer,nBytes,0,(struct sockaddr *)&server,addr_size);
    nBytes = recvfrom(clientSocket,buffer,1024,0,NULL, NULL);
    printf("Received from server: %s\n",buffer);

  }
  return 0;
}
