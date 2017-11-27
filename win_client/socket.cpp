#include<stdio.h>
#include <winsock2.h>
#include<stdlib.h>
#include<string.h>
#include "socket.h"


//===================win================================
bool InitWinSock()
{
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != NO_ERROR) {
        printf("WSAStartup function failed with error: %d\n", iResult);
        return false;
    }
	return true;
}

bool DestroyWinSock()
{
    WSACleanup();
	return true;
}
//===================win================================
bool FillSockAddr(sockaddr_in& sa, const char* szIP, const char* szPort)
{
    sa.sin_family = AF_INET;
	if (szIP == NULL)
	{
		sa.sin_addr.s_addr = INADDR_ANY;
	}
	else
	{
		sa.sin_addr.s_addr = inet_addr(szIP);
		if (sa.sin_addr.s_addr == INADDR_NONE)
		{
			printf("%s is not ip address!\r\n", szIP);
			return false;
		}
	}
	int nPort = atoi(szPort);
	if (nPort == 0)
	{
		printf("%s is not valid port!\r\n", szPort);
		return false;
	}
    sa.sin_port = htons(nPort);
	
	memset(sa.sin_zero, 0, sizeof(sa.sin_zero));

	return true;
}

/*
 * serverIp  :  服务器IP
 * serverPort： 服务器端口号
 * protocl   ：protocl -- tcp  不为其中两个，则默认为tcp
 * @                   -- udp  
 * @ 返回值： 返回已经连接的套接字
*/
SOCKET connectsock(const char *host, const char *service, const char *transport )
{
    sockaddr_in addr;
	if (!FillSockAddr(addr, host, service))
		return INVALID_SOCKET;

	SOCKET sock;
	int type;
	int protocol;

	if (strcmp(transport, "tcp") == 0)
	{
		type = SOCK_STREAM;
		protocol = IPPROTO_TCP;
	}
	else if (strcmp(transport, "udp") == 0)
	{
		type = SOCK_DGRAM;
		protocol = IPPROTO_UDP;
	}
	else
	{
		printf("unsupported protocol\r\n");
		return INVALID_SOCKET;
	}

    sock = socket(AF_INET, type, protocol);
    if (sock == INVALID_SOCKET) {
		ErrorHandler("create sock error!");
        return INVALID_SOCKET;
    }

    if (connect(sock, (SOCKADDR *) &addr, sizeof (addr)) == SOCKET_ERROR) {
		ErrorHandler("connect error!");
        closesocket(sock);
        return INVALID_SOCKET;
    }

	return sock;
}

void ErrorHandler(char* message)
{
	fprintf(stderr, "%s\n", message);
}
/*
 *@ 读取单个字符
*/
int SockReadChar(SOCKET sockfd, char * cPtr)
{

	static int charNum = 0;
	static char *read_ptr;
	static char buf[DATA_BUFFER_SIZE];

	if( charNum <= 0)
	{
		charNum = recv(sockfd,buf,DATA_BUFFER_SIZE - 1,0);
		if(charNum <= 0)		// EOF or SOCKET_ERROR
			return charNum;
		
		read_ptr = buf;
	}

	charNum--;
	*cPtr = *read_ptr++;
	return 1;
}

/*
 *@ 字符串尾部补 ‘\n’
 *@ 返回发送的字符数目
*/
int SockSendLine(SOCKET sockfd, const char * message)
{
	int iSend = 0; 
	char buf[DATA_BUFFER_SIZE];
	sprintf(buf, "%s\n", message);
	iSend = send(sockfd,buf,strlen(buf),0);
	return iSend;
}
/*
 *@ 读取一行数据
 *@ 返回读取的字符数
*/
int SockReadLine(SOCKET sockfd, char* buf)
{
	char c;
	char *ptr;
	int n;
	int ret;

	ptr = buf;
	for(n = 1;n < DATA_BUFFER_SIZE;n++)
	{
		ret = SockReadChar(sockfd,&c);
		if(ret == 1)
		{
			if(c == '\n')
				break;
			*ptr++ = c;
		}
		else		// EOF or SOCKET_ERROR
		{
			if(n==1)  // no data read
				return 0;
			else
				break;
		}
	}
	*ptr = 0;
	return n;
	
}

