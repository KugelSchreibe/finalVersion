#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>
#include "wn.h"
#include "server.h"
#include "wncontrol.h"
#include "wnadmin.h"
#include "wnsetting.h"

class MyTabWidget : public QTabWidget
{

    Q_OBJECT

private:

    QVector<QWidget*> allWindow; // создаем вектор в котором будем хранить укахзатели 4 главных окна

    int count; // переменная счетчик

    void pressEvent(QKeyEvent* pe); // метод обработки событий клавиатуры

public:

    MyTabWidget(QTabWidget* parent = nullptr); // конструктор

};

#endif // WIDGET_H
