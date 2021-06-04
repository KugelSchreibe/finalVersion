#ifndef SERVER_H
#define SERVER_H

#include <QtWidgets>
#include <QTcpSocket>
#include <QTcpServer>

class Server : public QLabel
{

    Q_OBJECT

private:

    QTcpServer* m_ptcpServer; // указатель на сервер

public:

    Server(quint16 nPort, QLabel* parent = nullptr); // консруктор

public slots:

    virtual void slotNewConnection(); // метод обработки
    void slotReadClient();

};

#endif // SERVER_H
