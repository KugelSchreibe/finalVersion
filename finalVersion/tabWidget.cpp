#include "tabWidget.h"

MyTabWidget::MyTabWidget(QTabWidget* parent) : QTabWidget(parent) {

    QStringList lst; // лист с названиями главных окон

    this->setWindowTitle("WALL-E");  //  установка названия окна с прокруткой виджетов

    lst << "WALL-E" << "Управление" << "Админ" << "Настройки"; // ввод названий окон

    allWindow.push_back(new Wn);         // создание четрех главных окон
    allWindow.push_back(new WnControl);
    allWindow.push_back(new WnAdmin);
    allWindow.push_back(new WnSetting);

    //allWindow[0]->setFocus(Qt::ActiveWindowFocusReason); // сделать как-то активным главное окно

    count = 0; // обнуляем счетчик для итерации по вектору с виджетами

    // с помощью цикла foreach присваиваем названия четырем окнам
    foreach(QString str, lst) {
        this->addTab(allWindow[count], str);
        count++;
    }

    this->setFixedSize(900, 900); // задаем размер окна с прокруткой виджетов

    count = 0; // обнуляем счетчик

    //setStyleSheet("QTabWidget { background-color: #59ff8e; border-style: outset; border-width: 2px; border-color: white;}");

}
