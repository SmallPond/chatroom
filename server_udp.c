// 我真诚地保证：
    
// 我自己独立地完成了整个程序从分析、设计到编码的所有工作。
// 如果在上述过程中，我遇到了什么困难而求教于人，那么，我将在程序实习报告中
// 详细地列举我所遇到的问题，以及别人给我的提示。

// 在此，我感谢 XXX, …, XXX对我的启发和帮助。下面的报告中，我还会具体地提到
// 他们在各个方法对我的帮助。

// 我的程序里中凡是引用到其他程序或文档之处，
// 例如教材、课堂笔记、网上的源代码以及其他参考书上的代码段,
// 我都已经在程序的注释里很清楚地注明了引用的出处。

// 我从未没抄袭过别人的程序，也没有盗用别人的程序，
// 不管是修改式的抄袭还是原封不动的抄袭。

// 我编写这个程序，从来没有想过要去破坏或妨碍其他计算机系统的正常运转。

// <丁标>

#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include "socket.h"
#include "common.h"
#include "list.h"

#define BACKLOG 5
//================用户注册宏========================
#define MAX_INFO_LEN            20
//注册成功
#define REGISTER_SUCCESS        0 
//重复注册
#define REGISTER_ERROR_REPEAT   1
//非法访问
#define REGISTER_ERROR_ILLEGAL  2
//================用户注册宏========================

//================用户登录宏========================
//登录成功
#define LOGIN_SUCCESS        3 
//登录失败
#define LOGIN_ERROR          4
//================用户登录宏========================
//================用户退出聊天室宏==================
#define QUIT_SUCCESS           5

//=================反馈信息=========================
char success[]     = "[+]success\n";
char repeat[]  	   = "[-]userName is exist\n";
char error[]       = "[-]Unauthorized access\n";
char loginError[]  = "[-]login error\n";
//=================反馈信息=========================

//===============用户信息链表头指针=================
ONLINE_INFO_NODE *pOnlineHead;
ONLINE_INFO_NODE *pUserHead;
//===============用户信息链表头指针=================


/*
 * @服务器端目前存在的问题
 	1.用户名密码如果存在中文无法解析与判断  ->【已经解决】 sscanf格式转换了一下， 通过客户端与服务器端配合解析
 	2.用户重复登录问题  -> [已有思路]
 	3.未解析用户注册信息， 没对非法字符进行判断
 	4.用户使用界面问题，具体在printf函数无法定位输出。 可能出现的情况，在用户键入信息到一半时，收到了一条信息，则会导致换行。
*/


/*
 * @获取本机时间，格式化输出
 * @timeBuf -> 输出参数，保存时间信息
*/
void GetTime(char * timeBuf)
{
    time_t now = time( 0 ); ;
    struct tm *tm_now;
    /*format date and time.*/
    strftime(timeBuf, 64 - 1, "%Y-%m-%d: %H:%M:%S", localtime(&now)); 
}

/*
 *@ recvMessage: 用户post信息
 *@ 返回值 ： 返回用户注册状态
*/

int UserRegister(ONLINE_INFO_NODE *pHead, USER_INFO userInfo)
{
	FILE* fp;
	ONLINE_INFO_NODE *p = pHead;
	
	// 用户名或者密码超过限制则认为非法
	if(strlen(userInfo.password) >= MAX_INFO_LEN || strlen(userInfo.password) >= MAX_INFO_LEN )
	{
		return REGISTER_ERROR_ILLEGAL;
	}
	//memset(fileBuf,0, DATA_BUFFER_SIZE);
	while(p != NULL)
	{
		if (strcmp(p->username, userInfo.username) == 0)
		{	
			// 用户名已经存在
			printf("name %s is exist\n",userInfo.username);
			return REGISTER_ERROR_REPEAT;
		}
		p = p->next;
	}

	if((fp = fopen("user_info.txt","a")) == NULL)
	{
		ErrorHandler("fopen() error");
		return -1;
	}
	//加入文件
	fprintf(fp,"%s %s\n",userInfo.username,userInfo.password);
	fclose(fp);
	//加入链表
	pUserHead = AddNode(pUserHead,userInfo);
	return REGISTER_SUCCESS;
	
}

/*
 *@ recvMessage: 用户post信息
 *@ 无返回值
*/
void UserMessageAnalyze(char * recvMessage, USER_INFO *userInfo)
{

	//format string
	sscanf(recvMessage,"%3d$%s $%s $%[^$]",&((*userInfo).action),(*userInfo).username,(*userInfo).password,(*userInfo).message);
	//printf("username:%s\n",(*userInfo).username);
	//printf("password:%s\n",(*userInfo).password);
	//printf("message:%s\n",(*userInfo).message);
}
/*
 * @反馈信息给客户端
*/
int Feedback(int sockfd, struct sockaddr* to, socklen_t addrlen, int status)
{
	//printf("反馈信息：[%s : %d] \r\n", inet_ntoa(*to.sin_addr), ntohs(*to.sin_port));  
	switch(status)
	{
		case REGISTER_SUCCESS:
			return sendto(sockfd, success,sizeof(success), 0, to, addrlen);

		case REGISTER_ERROR_REPEAT:
			return sendto(sockfd, repeat,sizeof(repeat), 0, to, addrlen);

		case REGISTER_ERROR_ILLEGAL:
			return sendto(sockfd, error,sizeof(error), 0, to, addrlen);

		case LOGIN_SUCCESS:
			return sendto(sockfd, success,sizeof(success), 0, to, addrlen);
		case LOGIN_ERROR:	
			return sendto(sockfd, loginError,sizeof(loginError), 0, to, addrlen);
		case QUIT_SUCCESS:
			return sendto(sockfd, success,sizeof(success), 0, to, addrlen);
		default:
			return -1;
	}
}

/*
 * @ 用户登录
*/
int UserLogin(ONLINE_INFO_NODE *pUserHead, ONLINE_INFO_NODE *pOnlineHead, USER_INFO userInfo)
{
	ONLINE_INFO_NODE *pU = pUserHead;
	ONLINE_INFO_NODE *pO = pOnlineHead;
	while(pU != NULL)
	{
		//此处可以添加是用户名错误还是密码错误， 但先不添加
		if ((strcmp(pU->username, userInfo.username) == 0) && (strcmp(pU->password, userInfo.password) == 0))
		{	
			/*
			// 用户名存在
			while(pO != NULL) 
			{
				//查看此用户是否已经登录
				if ((strcmp(pO->username, userInfo.username) == 0) && (strcmp(pO->password, userInfo.password) == 0))
				{
						//重复登录
				}
			}
			*/
			return LOGIN_SUCCESS;
		}
		pU = pU->next;
	}
	return LOGIN_ERROR;
}


int ServerSend(int sockfd, ONLINE_INFO_NODE *pHead,char *message)
{
	//显示所有在线用户
	//ShowAllNode(pHead);
	//链表遍历
	ONLINE_INFO_NODE *p = pHead;
	// 空链表
	while(p != NULL)
	{
		//printf("send message:%s ",message);
		int ret = sendto(sockfd, message, strlen(message), 0, (struct sockaddr*)&(p->cli_addr), p->client_len);
		//printf("send bytes: %d", ret);
		p = p->next;
	}
	printf("ServerSend() complete\n");
	return 0;
	
}

/*
 * @ 服务器功能选择
*/
void FunctionChoose(int sockfd, USER_INFO info)
{	
	int status;
	int ret;
	char sendBuf[1023];
	char timeBuf[64];
	switch(info.action)
	{
		case ACTION_REGISTER:
			/*User register*/
			status = UserRegister(pUserHead,info);
			ret = Feedback(sockfd, (struct sockaddr*)&(info.cli_addr), info.client_len, status);
			if(ret < 0)
			{
				ErrorHandler("状态反馈失败\n");
			}
			break;
		case ACTION_LOGIN:
			/*User login*/
			status = UserLogin(pUserHead,pOnlineHead, info);
			ret = Feedback(sockfd, (struct sockaddr*)&(info.cli_addr), info.client_len, status);
			if(ret < 0)
			{
				ErrorHandler("状态反馈失败\n");
			}
			if(status == LOGIN_SUCCESS)
			{
				/*登录成功则加入在线列表*/
				pOnlineHead = AddNode(pOnlineHead, info);
				//向所有在线用户发送此用户上线信息(包括新用户)
				char sendLogin[120];
				sprintf(sendLogin, "[system] -> [%s]:加入聊天室\n", info.username);
				ServerSend(sockfd,pOnlineHead, sendLogin);
				
			}
			break;
		
		case ACTION_START_CHAT:
			/*start chatting*/
			GetTime(timeBuf);
			sprintf(sendBuf, "[%20s]\t[%s]\n\t%s", info.username, timeBuf, info.message);
			//printf("message:%s", sendBuf);
			ServerSend(sockfd, pOnlineHead, sendBuf);
			break;
		case ACTION_QUIT:
			pOnlineHead = DeleteNode(pOnlineHead, info);
			//此时服务器需要反馈，不然客户端会卡在RECV函数！！！！！！！
			Feedback(sockfd, (struct sockaddr*)&(info.cli_addr), info.client_len, QUIT_SUCCESS);
			break;
	}
}
int UDPServer(const char* serverPort)
{

	int sServer;
        //cliet addr struct
	socklen_t clientLen;
	// 服务器地址结构体
	struct sockaddr_in ser;
	
	char recvBuf[DATA_BUFFER_SIZE];

	USER_INFO info;
	sServer = SocketInit("udp");
	if(sServer == -1)
	{
		ErrorHandler("SocketInit Faild\n");
		return -1;
	}
	
	if(SockaddrFill(&ser, NULL, serverPort) == -1)
	{
		ErrorHandler("SockaddrFill Faild \n");
		return -1;
	}
	//bind
	if(bind(sServer, (struct sockaddr* )&ser, sizeof(ser)) == -1)
	{
		ErrorHandler("bind() error");
	}
	//这句话很重要！！！！
	/*addrlen这个指针是一个传入传出指针，调用首先会使用addrlen这个值初始化src_addr这块缓冲区，
	然后修改返回真实大小的IP地址，如果提供的缓冲区太小，返回的地址也就是src_addr的内容会被截短，
	addrlen这个值会返回比调用时提供的值更大。
	不然返回的值就为[0.0.0.0 : 0]
	可参考 http://blog.csdn.net/u011478295/article/details/45010559?locationNum=10&fps=1
	*/
	info.client_len = sizeof(info.cli_addr);
	while(1)
	{
		
		memset(recvBuf,0,sizeof(recvBuf));	
		int iRecvLen = recvfrom(sServer, recvBuf, DATA_BUFFER_SIZE-1, 0, (struct sockaddr*)&(info.cli_addr), &(info.client_len));
		printf("接收连接：[%s : %d] \r\n", inet_ntoa(info.cli_addr.sin_addr), ntohs(info.cli_addr.sin_port));  
		recvBuf[iRecvLen+1] = '\0';
		if (iRecvLen == 0)
		{
			return -1;
		}
		else if (iRecvLen == -1)
		{
			ErrorHandler("recv() Failed:\n ");
			return -1;
		}
		else
		{
			printf("recv() data from clinet: %s", recvBuf);
		}
		
		/*解析用户数据*/
		UserMessageAnalyze(recvBuf,&info);
		/*服务器动作执行*/
		FunctionChoose(sServer, info);		
	}
	
	close(sServer);
	return 0;
}

int main(int argc, char* argv[])
{
	const char * serverPort;
	/*已经注册用户文件指针*/	
	FILE* fp;
	/*open the user_info.txt file*/
	if((fp = fopen("user_info.txt","r")) == NULL)
	{
		ErrorHandler("fopen() error");
		return -1;
	}
	if (argc < 2)
	{
		printf("usage: %s port\n",argv[0]);
		return -1;
	}
	serverPort = argv[1];
	
	//初始化注册用户信息链表
	InitList(&pUserHead);
	//初始化在线用户链表
	InitList(&pOnlineHead);
	//读入已经注册用户
	pUserHead = GetAllRegisterUser(pUserHead,fp);
	//ShowAllNode(pUserHead);

	
	//开启服务
	int ret = UDPServer(serverPort);
   	return ret;
}


