#ifndef __LIST_H__
#define __LIST_H__

#include <sys/socket.h>
#include <netinet/in.h>
#include "common.h"
typedef struct OnlineInfo{
	/*一下个客户端信息*/
	/*客户端地址*/
	struct sockaddr_in cli_addr;
	/*地址长度*/
	socklen_t client_len;

	/* 用户名 */ 
	char username[20];
	/* 密码 */
	char password[20];
	struct OnlineInfo * next;

}ONLINE_INFO_NODE;


/*初始化链表*/
void InitList(ONLINE_INFO_NODE  **pNode);
/*添加一个节点*/
ONLINE_INFO_NODE * AddNode(ONLINE_INFO_NODE *pHead, USER_INFO info);
/*删除节点*/
ONLINE_INFO_NODE * DeleteNode(ONLINE_INFO_NODE *pHead, USER_INFO info);
/* 检查单链表是否为空，若为空则返回１，否则返回０ */
int IsEmptyList(ONLINE_INFO_NODE *pHead);
/* 读入已注册用户表 */
ONLINE_INFO_NODE* GetAllRegisterUser(ONLINE_INFO_NODE *pHead, FILE* fp);
/*
 * 显示链表中所有节点
*/
int ShowAllNode(ONLINE_INFO_NODE *pHead);
#endif
