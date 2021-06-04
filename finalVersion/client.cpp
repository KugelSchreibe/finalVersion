#include "client.h"

Client::Client(const QString& strHost, int port, QWidget* wgt) : QWidget(wgt), host(strHost), port(port)
{
    TcpSocket = new QTcpSocket(this); // создание сокета
    TcpSocket->connectToHost(host, port); // подключение к серверу
}

void Client::pressButton(const QString &button)
{
    QByteArray arrBlock; // массив байтов
    QDataStream out(&arrBlock, QIODevice::WriteOnly); // поток байтов для записи массива байтов
    out.setVersion(QDataStream::Qt_5_10); // утсановка текущей версии Qt
    out.device()->seek(0);
    out << button; // запись в поток
    TcpSocket->write(arrBlock); // запись байтов в сокет
}

void Client::setPtrLabel(QLabel *ptr) // установка указаетеля на виджет
{
    ptrLabel = ptr;
    connect(this, SIGNAL(changeStateConnect(QString str)), ptr, SLOT(ptr->setText(str)));
}
