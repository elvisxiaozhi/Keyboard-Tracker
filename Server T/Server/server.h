#ifndef SERVER_H
#define SERVER_H

#include <QObject>

class Server : public QTcpServer
{
public:
    Server();
};

#endif // SERVER_H