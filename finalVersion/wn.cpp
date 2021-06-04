#include "wn.h"

Wn::Wn(QWidget* parents/*=0*/) : QWidget(parents)
{
    // устанавливаем в объект фона изображение
    fone.setBrush(this->backgroundRole(), QBrush(QPixmap("/home/sergei/QtProjects/QWALLE/pictureWALLE/600600uncolored_wall-e.jpg")));
    setPalette(fone); // устанавливем объект в виджет
    setAutoFillBackground(true);
}


// метод обработки событий клавиатуры
void Wn::keyPressEvent(QKeyEvent *pe) {
    qDebug() << pe->key();
    switch (pe->key()) {
    case Qt::Key_Escape: // если нажат ESC
    {
        QMessageBox::StandardButton reply; // создаем всплывающее окно
        reply = QMessageBox::question(nullptr, "Warning", "Закрыть приложение?", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) // если ответ ДА, выходим из приложения
            QApplication::quit();
        break;
    }
    }
}
