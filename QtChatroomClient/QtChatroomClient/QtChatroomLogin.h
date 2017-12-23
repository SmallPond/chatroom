#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtChatroomLogin.h"

class QtChatroomLogin : public QMainWindow
{
	Q_OBJECT

public:
	
	QtChatroomLogin(QWidget *parent = Q_NULLPTR);
	QtChatroomLogin(QWidget *parent, int socket);
	~QtChatroomLogin();
	int LoginChatroom(int socketfd, std::string username, std::string password);
	int RegisterAccount(int socketfd, std::string username, std::string password);
signals:
	void showchatroom(QString );

private slots:
	void receiveshowlogin();
	void Login();
	void OnRegister();
private:
	int clientsock;
	Ui::QtChatroomLoginClass ui;
};
