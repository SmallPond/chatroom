#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include "socket.h"

/*
 * serverIp  :  服务器IP
 * serverPort： 服务器端口号
 * protocl   ：protocl -- tcp  不为其中两个，则默认为tcp
 * @                   -- udp  
 * @ 返回值： 返回已经连接的套接字
*/
int ConnectSocket(const char* serverIp, const char *serverPort, const char * protocl)
{
	int sClient;
	struct sockaddr_in ser;
	
	sClient = SocketInit(protocl);
	if(sClient == -1)
	{
		printf("SocketInit Faild\n");
		return -1;
	}
	
	if(SockaddrFill(&ser, serverIp, serverPort) == -1)
	{
		printf("SockaddrFill Faild \n");
		return -1;
	}

	if (connect(sClient, (struct sockaddr*)&ser, sizeof(ser)) == -1)
	{
		printf("connect() Failed: \n");
		return -1;
	}
	return sClient;
}

void ErrorHandler(char* message)
{
	fprintf(stderr, "%s\n", message);
}
/*
 *@ 读取单个字符
*/
int SockReadChar(int sockfd, char * cPtr)
{

	static int charNum = 0;
	static char *read_ptr;
	static char buf[DATA_BUFFER_SIZE];

	if( charNum <= 0)
	{
		charNum = read(sockfd,buf,DATA_BUFFER_SIZE - 1);
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
int SockSendLine(int sockfd, const char * message)
{
	int iSend = 0; 
	char buf[DATA_BUFFER_SIZE];
	strcpy(buf,message);
	strcat(buf,"\n");
	iSend = send(sockfd,buf,strlen(buf),0);
	return iSend;
}
/*
 *@ 读取一行数据
 *@ 返回读取的字符数
*/
int SockReadLine(int sockfd, char* buf)
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
/*
 *@ socket 地址填充
*/
int SockaddrFill(struct sockaddr_in * sockaddr, const char* serIp, const char* serPort)
{
	(*sockaddr).sin_family = AF_INET;
	//IP addr 
	if(serIp == NULL)      //一般用于服务器的初始化
	{
		(*sockaddr).sin_addr.s_addr = htonl(INADDR_ANY);
	}
	else
	{
		(*sockaddr).sin_addr.s_addr = inet_addr(serIp);
	}
	
	if ((*sockaddr).sin_addr.s_addr == INADDR_NONE)
	{
		printf("ip %s is not a valid ip address\n", serIp);
		return -1;
	}
	// IP port 
   	(*sockaddr).sin_port = htons(atoi(serPort));
	if ((*sockaddr).sin_port == 0)
	{
		printf("port %s is not a valid port\n", serPort);
		return -1;
	}

	return 0;
}

/*
 * @ socket Init
 * @ protocl -- tcp 
 * @         -- udp 
*/
int SocketInit(const char* protocl)
{
	int socket_temp;
	
	if(strcmp(protocl, "tcp") == 0)
	{
		socket_temp = socket(AF_INET, SOCK_STREAM, 0);
		
	}
	else if(strcmp(protocl, "udp") == 0)
	{
		socket_temp = socket(PF_INET, SOCK_DGRAM, 0);
	}
	else
	{
		// 输入错误 默认TCP
		socket_temp = socket(AF_INET, SOCK_STREAM, 0);
	}
	
	return socket_temp;
}


