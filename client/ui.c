#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "common.h"


/*显示菜单*/
void ShowMenu()
{
	//清屏
	//system("clear");
	printf("|------------welcome to Happy chatroom-------------\t\n");
	printf("|1.注册用户\n");
	printf("|2.加入聊天室\n");
	printf("|------------welcome to Happy chatroom-------------\t\n");
	printf("没有注册用户？ 输入 '1' 注册一个用户吧--------\n");
	printf("已经注册用户？ 输入 '2' 登录聊天室吧--------\n");

}

