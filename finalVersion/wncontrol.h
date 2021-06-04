#ifndef WNCONTROL_H
#define WNCONTROL_H

#include <QtWidgets>
#include "client.h"
#include "server.h"

class WnControl : public QWidget
{

    Q_OBJECT

private:

   QCheckBox* CBw = new QCheckBox; // создаем указатели на кнопки управления
   QCheckBox* CBa = new QCheckBox;
   QCheckBox* CBs = new QCheckBox;
   QCheckBox* CBd = new QCheckBox;
   QCheckBox* CBt = new QCheckBox;
   QCheckBox* CBf = new QCheckBox;
   QCheckBox* CBg = new QCheckBox;
   QCheckBox* CBh = new QCheckBox;
   QCheckBox* CBi = new QCheckBox;
   QCheckBox* CBj = new QCheckBox;
   QCheckBox* CBk = new QCheckBox;
   QCheckBox* CBl = new QCheckBox;

   QLabel* tempScreen; // виджет вывода кадров с клинта

   void keyPressEvent(QKeyEvent* pe); // метод обработки нажатия на клавиши
   void keyReleaseEvent(QKeyEvent* pe); // метода обработки отпускания клавиш

public:

   Client* myClient = new Client("127.0.0.1", 5556); // создание клинта для дальнейшей отправки нажатых клавиш

   WnControl(QWidget* parents = nullptr); // конструктор

};

#endif // WNCONTROL_H
