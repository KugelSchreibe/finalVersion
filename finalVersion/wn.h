#ifndef WN_H
#define WN_H

#include <QtWidgets>

class Wn : public QWidget
{
    Q_OBJECT

private:

    QPalette fone; // фон

    void keyPressEvent(QKeyEvent* pe); // метод обработки событий клавиатуры

public:

    Wn(QWidget* parents = nullptr); // конструктор

public slots:

};

#endif // WN_H
