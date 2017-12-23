#ifndef __SOCKET_H__
#define __SOCKET_H__

#include<ws2tcpip.h>
#include<QMessageBox>

#define DATA_BUFFER_SIZE 4098

SOCKET connectsock(const char *host, const char *service, const char *transport);
bool DestroyWinSock();
bool InitWinSock();
int SockaddrFill(struct sockaddr_in * sockaddr, const char* serIp, const char* serPort);
void ErrorHandler(std::string message);
int SockReadChar(SOCKET sockfd, char * cPtr);
int SockReadLine(SOCKET sockfd, char* buf);

int SockSendLine(SOCKET sockfd, const char * message);
#endif 
