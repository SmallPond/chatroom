#include "QtChatroomClient.h"
#include <QMessageBox>
#include <string>
#include <vector>
#include "chatClient.h"
#include "socket.h"

#define SERVER_USER_JION_MESS    0
#define SERVER_CHAT_MESS   	     1
#define	SERVER_ONLINE_LIST_MESS  2
#define SERVER_USER_QUIT_MESS    3

QtChatroomClient::QtChatroomClient(QWidget *parent)
	:QDialog(parent)
{
	ui.setupUi(this);
}

QtChatroomClient::QtChatroomClient(QWidget *parent, int socket)
	:QDialog(parent), clientsock(socket), nTh(Q_NULLPTR, socket)
{
	ui.setupUi(this);
}


QtChatroomClient::~QtChatroomClient()
{
}

//==================SLOT==================
void QtChatroomClient::receiveshowchatroom(QString name)
{

	this->show();

	this->username = name.toStdString();
	//开启网络线程
	nTh.start();
	/*信号与槽连接*/
	QObject::connect(&nTh, SIGNAL(chatsignal(char*)), this, SLOT(OnChat(char*)));
	QObject::connect(&nTh, SIGNAL(listsignal(char*)),       this, SLOT(OnList(char* )));
	QObject::connect(&nTh, SIGNAL(joinsignal(const char*)), this, SLOT(OnJoin(const char*)));
	QObject::connect(&nTh, SIGNAL(quitsignal(const char*)), this, SLOT(OnQuit(const char*)));
	ui.chatListWidget->addItem(tr("\tWelcome to Happy Chatroom"));
	ui.onlineListWidget->addItem(tr("   Online User List"));
}
void QtChatroomClient::OnChat(char* message)
{
	char timeBuf[20];
	char* name = strtok(message, ":");
	char* msg = strtok(NULL, ":");
	char showMsg[2048];
	GetTime(timeBuf);
	sprintf(showMsg, "[%15s]\t%s\n\t%s", name, timeBuf, msg);
	ui.chatListWidget->addItem(tr(showMsg));

}
void QtChatroomClient::OnList(char* message)
{
	
	char* tmpStr = strtok(message,"&");
	while (tmpStr != NULL)
	{
		ui.onlineListWidget->addItem("[+] " + tr(tmpStr));
		tmpStr = strtok(NULL, "&");
	}
}
void QtChatroomClient::OnJoin(const char* username)
{

	ui.chatListWidget->addItem("\t [system] ->" + tr(username) + "join happy room");
	ui.onlineListWidget->addItem("[+] " + tr(username));
}
void QtChatroomClient::OnQuit(const char* username)
{
	ui.chatListWidget->addItem("\t [system] ->" + tr(username) + "quit happy room");
	/*行是从0还是1开始！！！*/
	for (int i = 0; i < ui.onlineListWidget->count(); i++)
	{

	}
}
void QtChatroomClient::SendButton()
{
	int  iSend;
	std::string message = ui.inputTextEdit->toPlainText().toStdString();
	ui.inputTextEdit->clear();
	Post(clientsock, ACTION_START_CHAT, username.data(), "*", message.data());
}


//==================SLOT==================


/*
* 网络数据读取线程
*/
void NetworkThread::run()
{
	/* 无类型指针转换为整型指针再读取*/
	int infoType = 0;
	char message[DATA_BUFFER_SIZE];

	while (1)
	{
		char recvBuf[DATA_BUFFER_SIZE];
		memset(recvBuf, 0, sizeof(recvBuf));

		// 接收服务器反馈
		int iLen = Get(socket, recvBuf);
		if (iLen > 0)
		{

			printf("%s\n", recvBuf);
			sscanf(recvBuf, "%d %[^$]", &infoType, message);
			printf("infoTpye %d", infoType);
			switch (infoType)
			{
				case SERVER_USER_JION_MESS:
					emit joinsignal(message);
					break;
				case SERVER_CHAT_MESS:
					emit chatsignal(message);
					break;
				case SERVER_ONLINE_LIST_MESS:
					emit listsignal(message);
					break;
				case SERVER_USER_QUIT_MESS:
					emit quitsignal(message);
					break;
				default:
					printf("infoType error\n");
			}
		}
		else
		{
			ErrorHandler("Get() Error \n");
		}
	}
}