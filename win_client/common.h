
#ifndef __COMMON_H__
#define __COMMON_H__


#include<ws2tcpip.h>


typedef struct User{

	socklen_t client_len;
	struct sockaddr_in cli_addr;
	int action;
	char username[20];
	char password[20];
	char message[1024];
}USER_INFO;

//注册
#define ACTION_REGISTER        1
//登录聊天室
#define ACTION_LOGIN           2
//开始聊天
#define ACTION_START_CHAT      3
//退出聊天室
#define ACTION_QUIT        	   4


#endif
