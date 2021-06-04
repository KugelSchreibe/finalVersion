#include "server.h"

Server::Server(quint16 nPort, QLabel* parent) : QLabel(parent)
{
    setText("Подключение..."); // установка надписи

    setFrameStyle(QFrame::Box); // установка рамки вокруг видео

    m_ptcpServer = new QTcpServer(this); // присвоение указателя на сервер
    if(!m_ptcpServer->listen(QHostAddress::Any, nPort)) // проверка подключения
    {
        QMessageBox::critical(nullptr, "Server Error", "Unable to start the server:" + m_ptcpServer->errorString());
        m_ptcpServer->close();
        return;
    }

    QMessageBox::information(nullptr, "Server", "Server is running"); // вывод информации об успехе запуска сервера

    connect(m_ptcpServer, SIGNAL(newConnection()), this, SLOT(slotNewConnection())); // соединения слота нового подключения со слотом
}



void Server::slotNewConnection()
{
    qDebug() << "новое соединение\n";

    QTcpSocket* pClientSocket = m_ptcpServer->nextPendingConnection(); // ожидание подключения
    connect(pClientSocket, SIGNAL(disconnected()), pClientSocket, SLOT(deleteLater())); // сигнал-слот ошибки подключения
    connect(pClientSocket, SIGNAL(readyRead()), this, SLOT(slotReadClient())); // сигнал-слот считывания сокета
}



void Server::slotReadClient()
{
    QTcpSocket* pClientSocket = static_cast<QTcpSocket*>(sender());
    QByteArray buff; // массив байтов

    QPixmap pix; // объект картинки
    buff.append(pClientSocket->readAll()); // считывание сокета
    pix.loadFromData(buff); // преобразование байт в картинку
    setPixmap(pix); // утсановка картинки
    buff.clear(); // очистка массива
}
