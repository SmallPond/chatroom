
#include<stdio.h>
#include <winsock2.h>
#include<stdlib.h>
#include<string.h>
#include< Windows.h>
#include "socket.h"
#include "common.h"
#include "ui.h"
#include "cursor.h"

/* 程序功能：
  客户端发送用户名，密码给服务器 
  并接收服务器的返回状态
*/

//==============全局用户名密码====================
char username[20];
char password[20];
//==============全局用户名密码====================

// 退出聊天室
int quitFlag = 1;

/*
 *@ 返回值： 发送的总字节数
*/
int Post(SOCKET socketfd, int action , const char *userName, const char * password, const char* message)
{
	int iSend = 0;
	
	char postInfo[128];
	memset(postInfo,0,sizeof(postInfo));
	
	// 使用$分割字符串，方便服务器端的解析
	// action username password message
	sprintf(postInfo,"%d$%s $%s $%s$",action, userName, password, message);
	
	iSend = SockSendLine(socketfd, postInfo);
	if(iSend <= 0)
	{
			ErrorHandler("Post() Error\n");
			exit(1);
	}
	else
	{
		//printf("Post: %s\n", postInfo);
	}
	return iSend;
}

/*
 * 返回接收到的字节数
*/
int Get(SOCKET socketfd, char* recvBuf)
{

	int iLen;
	iLen = recv(socketfd, recvBuf, DATA_BUFFER_SIZE-1, 0);
	recvBuf[iLen]='\0';
	if (iLen == 0)
	{
		printf("connect closed\n");
		exit(1);
	}
	else if (iLen == -1)
	{
		printf("recv() Failed:\n ");
		exit(1);
	}
	else
	{
		//printf("recv() from server: %s\n", recvBuf);
	}
	
	return iLen;
}


/*
 * 用户注册，直到注册成功
 *@ 无返回值
*/
void UserRegister(SOCKET socketfd)
{
	int successFlag = 0;
	int iLen;
	char username[20];
	char password[20];
	
	while(!successFlag)
	{
		printf("请输入你的用户名（由字母、数字或下划线组成）：");
		scanf("%s",username);
		printf("请输入你的密码（由字母、数字或下划线组成）：");
		scanf("%s",password);
	
		/*发送到服务器*/
		int ret = Post(socketfd, ACTION_REGISTER , username, password, "reister");
		
		//recv from server register information
		char recvBuf[DATA_BUFFER_SIZE];
		int iLen = Get(socketfd, recvBuf);
		
		printf("%s\n", recvBuf);
		if(strcmp(recvBuf,"[+]success\n") == 0)
		{
			printf("恭喜你，注册成功\n");
			successFlag = 1;
		}
		else
		{
			printf("重新输入\n");
		}
	}

}

/*
 * 登录聊天室
 * 返回值： 1 成功  0 失败
*/
int LoginChatroom(SOCKET socketfd)
{
	printf("请输入你的用户名：");
	scanf("%s",username);
	printf("请输入你的密码：");
	scanf("%s",password);	
			
	/*发送到服务器*/
	int ret = Post(socketfd, ACTION_LOGIN , username, password, "login");

	char recvBuf[DATA_BUFFER_SIZE];
	memset(recvBuf,0,sizeof(recvBuf));
	// 接收服务器反馈
	int iLen = Get(socketfd, recvBuf);
	
	printf("%s\n", recvBuf);
	if(strcmp(recvBuf,"[+]success\n") == 0)
	{
		printf("恭喜你，登录成功\n");
		return 1;
	}
	else
	{
		printf("登录失败，按任意键继续\n");
		fgetc(stdin);
		return 0;
	}
	
	
}
/*
 * @ 读取用户输入并发送线程
 × @ 若读取到 ESC 退出聊天室 
*/
DWORD WINAPI ChatPost(LPVOID args)
{
	
	/* 无类型指针转换为整型指针再读取*/
	SOCKET socketfd =*((SOCKET*)args);
	char postBuf[DATA_BUFFER_SIZE];
	char * pBuf = postBuf;
	char inputChar;
	char charCount = 0;
	
	while(1 && quitFlag)
	{
		//MOVETO(20,40);
		//printf("---------------------\n");
		charCount = 0;
		memset(postBuf,0, sizeof(postBuf));
		pBuf = postBuf;
		while((inputChar=getchar())!= '\n')
		{
			//printf("进入子线程，开始读取用户输入\n");
			*pBuf++ = inputChar;
			charCount++;
			// 防止溢出
			if(charCount >= DATA_BUFFER_SIZE - 1)
			{
				postBuf[charCount] = '\n';
				break;
			}
			/*ESC按键*/
			if(inputChar == 0x1B)
			{
				quitFlag = 0;
				int ret = Post(socketfd, ACTION_QUIT , username, password, "quit");
				break;
			}
			
		}
		
		/*回车发送信息到服务器*/
		if(strlen(postBuf) >= 2)
		{
			//空串则不发送
			Post(socketfd, ACTION_START_CHAT , username, password, postBuf);  //开始聊天状态，由服务器处理
		}
		//RESET_CURSOR();
		
	}
	printf("线程退出\n");
	return 0;
}
/*
 * @ 开始聊天
 * @ 多线程，子线程用来读取用户输入， 使用 pthread 创建线程
*/
int StartChat(SOCKET socketfd)
{

	system("cls");
	printf("\t\t------------welcome to Happy chatroom-------------\t\n\n");
	
	//开启线程
	if(CreateThread(NULL, 0, ChatPost, LPVOID (&socketfd), 0, NULL) == NULL)
	{
		ErrorHandler("开启线程失败\n");
		return -1;
	}
	
	while(1 && quitFlag)
	{
		char recvBuf[DATA_BUFFER_SIZE];
		memset(recvBuf,0,sizeof(recvBuf));
		
		// 接收服务器反馈
		int iLen = Get(socketfd, recvBuf);
		if (iLen > 0)
		{
			//RESET_CURSOR();
			printf("\t%s\n", recvBuf);
		}
		else
		{
			ErrorHandler("Get() Error \n");
			return -1;
			//exit(1);
		}
	}
	printf("退出聊天状态\n");
	return 0;
}
/*
 *@ 使用 connected udp
*/
int UDPClient(const char* serverIp, const char *serverPort)
{
	
	int iSend;
	SOCKET sClient;
	int userAction;
	int status;
	// 服务器地址结构体
	struct sockaddr_in ser;
	
	sClient = connectsock(serverIp, serverPort, "udp");
	if(sClient == -1)
	{
		ErrorHandler("ConnectSocket() Faild\n");
		return -1;
	}
	
	while(1)
	{
		ShowMenu();
		// 退出后重新将标志置为1；
		quitFlag = 1;
		do
		{
			scanf("%d",&userAction);
			if(userAction == ACTION_LOGIN || userAction == ACTION_REGISTER)
			{
				// 读取到有效指令便退出
				break;
			}
			else
			{
				printf("你输入的指令有误，请重新输入指令号\n");
			}
			
		}while(1);
		
		switch(userAction)
		{
			case ACTION_REGISTER:
				UserRegister(sClient);
				break;
			case ACTION_LOGIN:
			    status = LoginChatroom(sClient);
				if(status == 0)
				{
					break;
				}
				/*登录成功直接进入聊天室， 不再break*/
			case ACTION_START_CHAT:
				//开始聊天
				StartChat(sClient);
				break;
			default:
				break;
			
		}
	}

	closesocket(sClient);
	return 0;
	
}

int main(int argc, char* argv[])
{
	if (!InitWinSock())
		return 1;

	const char * serverPort;
	const char * serverIp;
	if (argc < 3)
	{
		printf("usage: %s ip port\n",argv[0]);
		return -1;
	}
	serverIp   = argv[1];
	serverPort = argv[2];
	system("cls");
	int ret = UDPClient(serverIp,serverPort);
	
	DestroyWinSock();
	
   	return ret;
}

