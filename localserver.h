/**
  *@file localserver.h
  * @version 1.0
  * @date 25/09/2020
  * @author Luis Andrey Zuniga
  * @title LocalServer
  * @brief Used to recieve and response from the socket
  */
#ifndef LOCALSERVER_H
#define LOCALSERVER_H

#include <QObject>
#include<QLocalServer>
class QLocalSocket;
class LocalServer : public QLocalServer
{
    Q_OBJECT
public:
    explicit LocalServer(QObject *parent = nullptr);
    /**
     * @brief Handles what to do when the request from the socket its recieved
     */
    void handle();
    /**
     * @brief startListening to the socket at the name selected
     * @param serverName
     */
    void startListening(QString serverName);
    /**
     * @brief write some data to the socket
     * @param QString representing the text to be sended
     */
    void write(QString text);


private:
    /**
     * @brief QLocalSocket to handle outside info
     */
    QLocalSocket * mSocket;
signals:
    /**
     * @brief a signal given each time the socket recieves a message
     */
    void incomingText(QString);


};

#endif // LOCALSERVER_H
