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
    void handle();
    void startListening(QString serverName);
    void write(QString text);


private:
    QLocalSocket * mSocket;
signals:
    void incomingText(QString);


};

#endif // LOCALSERVER_H
