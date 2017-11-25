#ifndef __SOCKET_H__
#define __SOCKET_H__

#include<sys/socket.h>
#define DATA_BUFFER_SIZE 4098

int SockaddrFill(struct sockaddr_in * sockaddr, const char* serIp, const char* serPort);
int SocketInit(const char* protocl);
void ErrorHandler(char* message);
int SockReadChar(int sockfd, char * cPtr);
int SockReadLine(int sockfd, char* buf);
int SockSendLine(int sockfd, const char * message);
int ConnectSocket(const char* serverIp, const char *serverPort, const char * protocl);
#endif 
