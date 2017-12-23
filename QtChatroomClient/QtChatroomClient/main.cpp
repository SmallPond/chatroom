#include "QtChatroomLogin.h"
#include "QtChatroomClient.h"
#include <QtWidgets/QApplication>
#include "socket.h"

int main(int argc, char *argv[])
{
	if (!InitWinSock())
		return 1;

	int sClient = 0;
	QApplication app(argc, argv);
	sClient = connectsock("120.78.209.0", "5656", "tcp");
	if (sClient == -1)
	{
		return -1;
	}
	QtChatroomLogin loginW(Q_NULLPTR, sClient);
	QtChatroomClient clientW(Q_NULLPTR, sClient);
	QObject::connect(&loginW, SIGNAL(showchatroom(QString)), &clientW, SLOT(receiveshowchatroom(QString)));
	QObject::connect(&clientW, SIGNAL(showlogin()), &loginW, SLOT(receiveshowlogin()));

	loginW.show();
	return app.exec();
	DestroyWinSock();

}
