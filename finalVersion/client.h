#ifndef CLIENT_H
#define CLIENT_H

#include <QtWidgets>
#include <QTcpSocket>

using namespace std;

class Client : public QWidget
{
    Q_OBJECT

private:

    QTcpSocket* TcpSocket; // создание указателя на сокет

    QString host; // хост и порт
    int port;

    QLabel* ptrLabel = nullptr;

public:
    Client(const QString& strHost, int port, QWidget* parent = nullptr);
    void pressButton(const QString&); // метод регистрации нажатых клавиш
    void setPtrLabel(QLabel*); // установка указателя на виджет вывода видео
};

#endif // CLIENT_H
