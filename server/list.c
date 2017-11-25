#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "common.h"
#include "socket.h"

/*初始化链表, 置单链表的表头为空*/
void InitList(ONLINE_INFO_NODE  **pNode)
{
	*pNode = NULL;
	//printf("The linked list init success\n");
}

/*
 *@添加一个节点到表头
 *@刚加入的用户更容易退出，方便用户的删除
*/
ONLINE_INFO_NODE * AddNode(ONLINE_INFO_NODE *pHead, USER_INFO info)
{
	ONLINE_INFO_NODE  *pNode;

	//申请空间
	pNode = (ONLINE_INFO_NODE * )malloc(sizeof(ONLINE_INFO_NODE));
	if(pNode != NULL)
	{
		//printf("memory application is successful\n");
	}
	else
	{
		printf("memory application is falied\n");
	}
	pNode->cli_addr = info.cli_addr;
	pNode->client_len = info.client_len;
	strcpy(pNode->username, info.username);
	strcpy(pNode->password, info.password);

	//将节点加入链表
	if(pHead == NULL)
	{
		//链表为空
		pHead = pNode;
	}
	else
	{
		pNode->next = pHead;
		pHead = pNode;
	}
	return pHead;
}
/*
 *@指定用户名删除节点
 *@返回值： 0 成功
			-1失败
 */
ONLINE_INFO_NODE * DeleteNode(ONLINE_INFO_NODE *pHead, USER_INFO info)
{
	ONLINE_INFO_NODE *p = pHead;
	ONLINE_INFO_NODE *s = pHead;
	
	if(IsEmptyList(p))
	{
		//链表为空直接返回
		return NULL;
	}
	//如果删除的为第一个节点
	if(strcmp(p->username, info.username) == 0 )
	{
		pHead = p->next;
		free(p);
		printf("用户:%s离线成功\n",info.username);
		return pHead;
	}
	//如果不是，跳过头节点
	p = p->next;
	while(p != NULL)
    	{
		if(strcmp(p->username, info.username) == 0)
		{
			s->next = p->next;
			//释放内存			
			free(p);
			printf("用户:%s离线成功\n",info.username);
			return pHead;
		}
		//指向下一节点
		s = p;
       	        p = p->next;
		
    	}

	return pHead;
}

/*
 * 读入已注册用户表
*/
ONLINE_INFO_NODE* GetAllRegisterUser(ONLINE_INFO_NODE *pHead, FILE* fp)
{
	ONLINE_INFO_NODE *p = pHead;
	
	/*User information struct*/
	USER_INFO userInfo;
	/*buf */
	char fileBuf[DATA_BUFFER_SIZE];

	printf("读入注册用户:\n");
	
	memset(fileBuf,0, DATA_BUFFER_SIZE);
	
	while (fgets(fileBuf, DATA_BUFFER_SIZE - 1, fp))
	{
		
		sscanf(fileBuf,"%s %s", userInfo.username, userInfo.password);
		pHead = AddNode(pHead, userInfo);
		
	}
	fclose(fp);
	return pHead;
}
/*
 * 显示链表中所有节点
*/
int ShowAllNode(ONLINE_INFO_NODE *pHead)
{
	ONLINE_INFO_NODE *p = pHead;
	IsEmptyList(p);
	//printf("online user:\n");
	while(p != NULL)
	{
		printf("[+]%s\n",p->username);
		p = p->next;
	}
	return 0;
}
/* 检查单链表是否为空，若为空则返回１，否则返回０ */
int IsEmptyList(ONLINE_INFO_NODE *pHead)
{
    if(pHead == NULL)
    {
        printf("isEmptyList函数执行，链表为空\n");
        return 1;
    }
    //printf("isEmptyList函数执行，链表非空\n");
 
    return 0;
}

/*测试链表*/
/*
int main()
{
       ONLINE_INFO_NODE *pList ;

	USER_INFO info[10];

	strcpy(info[0].username,"dd10");
	strcpy(info[1].username,"dd11");
	strcpy(info[2].username,"dd12");
	strcpy(info[3].username,"dd13");
    	InitList(&pList);   //链表初始化

	pList = AddNode(pList,info[0]);

	pList = AddNode(pList,info[1]);
	
	pList = AddNode(pList,info[2]);
    	ShowAllNode(pList);   //遍历链表，打印链表
	pList = DeleteNode(pList,info[0]);
    	ShowAllNode(pList);
	return 0;
}
*/
