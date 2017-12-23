#pragma once

#include<QDialog>
#include<QThread>
#include "ui_QtChatroomClient.h"

class NetworkThread :public QThread {
	Q_OBJECT
public:
	NetworkThread(QObject *parent = 0) {}
	NetworkThread(QObject *parent, int sock) :QThread(parent), socket(sock) {}

protected:
	void run();
signals:
	void chatsignal(char*);
	void listsignal(char*);
	void joinsignal(const char*);
	void quitsignal(const char*);
private:
	int socket;

};

class QtChatroomClient : public QDialog
{
	Q_OBJECT

public:
	QtChatroomClient(QWidget *parent = Q_NULLPTR);
	QtChatroomClient(QWidget *parent, int socket);
	~QtChatroomClient();



signals:
	void showlogin();

private slots:
	void receiveshowchatroom(QString);
	void SendButton();
	//=========信息槽===========
	void OnChat(char*);
	void OnList(char*);
	void OnJoin(const char*);
	void OnQuit(const char*);
	//=========信息槽===========
private:
	
	std::string username;
	std::string password;
	int clientsock;
	Ui::QtChatroomClientClass ui;
	NetworkThread nTh;
};


