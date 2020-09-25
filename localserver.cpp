#include "localserver.h"
#include<QLocalSocket>
#include<QLocalServer>
#include <qmessagebox.h>
#include <QTextStream>
#include<iostream>

LocalServer::LocalServer(QObject *parent) : QLocalServer(parent)
{
    mSocket=nullptr;
    connect(this,&LocalServer::newConnection,[&]{
       mSocket=nextPendingConnection();
       connect(mSocket,&QLocalSocket::readyRead,[&]{
           handle();
       });
    });
}
void LocalServer::handle(){
    std::cout<<"Pos he llegado"<<std::endl;
   emit incomingText( mSocket->readAll());
}
void LocalServer::startListening(QString serverName){
    listen(serverName);
}

void LocalServer::write(QString text)
{
    if(mSocket==nullptr)return;
    QTextStream T(mSocket);
    T<<text;
    mSocket->flush();
}

