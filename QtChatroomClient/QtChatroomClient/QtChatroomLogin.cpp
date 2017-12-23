#include "QtChatroomLogin.h"
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include "chatClient.h"
#include "socket.h"




QtChatroomLogin::QtChatroomLogin(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

QtChatroomLogin::QtChatroomLogin(QWidget *parent, int socket)
	:QMainWindow(parent), clientsock(socket)
{
	ui.setupUi(this);
}

QtChatroomLogin::~QtChatroomLogin()
{

}
void QtChatroomLogin::receiveshowlogin()
{
	this->show();
}



int QtChatroomLogin::RegisterAccount(int socketfd, std::string username, std::string password)
{
	/*发送到服务器*/
	int ret = Post(socketfd, ACTION_REGISTER, username.data(), password.data(), "reister");

	//recv from server register information
	char recvBuf[DATA_BUFFER_SIZE];
	int iLen = Get(socketfd, recvBuf);

	printf("%s\n", recvBuf);
	if (strcmp(recvBuf, "[+]success") == 0)
	{
		printf("恭喜你，注册成功\n");
		return true;
	}
	else
	{
		if (strcmp(recvBuf, "[-]userName is exist") == 0)
		{
			QMessageBox::information(this, tr("error"), tr("userName is exist"));
		}
		else if (strcmp(recvBuf, "[-]Unauthorized access") == 0)
		{
			QMessageBox::information(this, tr("error"), tr("Unauthorized"));
		}
		return false;
	}
}

int QtChatroomLogin::LoginChatroom(int socketfd, std::string username, std::string password)
{
	/*发送到服务器*/
	int ret = Post(socketfd, ACTION_LOGIN, username.data(), password.data(), "login");

	char recvBuf[DATA_BUFFER_SIZE];
	memset(recvBuf, 0, sizeof(recvBuf));
	// 接收服务器反馈
	int iLen = Get(socketfd, recvBuf);

	printf("%s\n", recvBuf);
	if (strcmp(recvBuf, "[+]success") == 0)
	{
		return true;
	}
	else
	{
		if (strcmp(recvBuf, "[-]username or password is wrong") == 0)
		{
			QMessageBox::information(this, tr("error"), tr("Username or password is wrong"));
		}
		else if (strcmp(recvBuf, "[-]Repeat login") == 0)
		{
			QMessageBox::information(this, tr("error"), tr("The user is already logged in"));
		}

		return false;
	}
}


void QtChatroomLogin::Login()
{
	QString user = ui.userLineEdit->text();
	QString pass  = ui.passLineEdit->text();
	
	if (LoginChatroom(clientsock, user.toStdString(), pass.toStdString()))
	{
		this->hide();
		emit showchatroom(user);
	}
	
	
}
void QtChatroomLogin::OnRegister()
{
	QString user = ui.userLineEdit->text();
	QString pass = ui.passLineEdit->text();

	if (RegisterAccount(clientsock, user.toStdString(), pass.toStdString()))
	{
		this->hide();
		emit showchatroom(user);
	}
}