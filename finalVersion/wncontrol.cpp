#include "wncontrol.h"

WnControl::WnControl(QWidget* parent) : QWidget(parent)
{
    setFixedSize(900, 900); // задаем размер окна

    tempScreen = new Server(2323); // создаем сервер

    QLabel* sens = new QLabel; // виджеты для описания
    QLabel* gus = new QLabel;
    QLabel* cum = new QLabel;
    QLabel* gusControl = new QLabel;
    QLabel* handsControl = new QLabel;
    QLabel* cumControl = new QLabel;

    QSpinBox* gusSB = new QSpinBox; // виджеты прокрутки значений
    QSpinBox* cumSB = new QSpinBox;

    cumSB->setMaximum(3); // стартовые значения
    cumSB->setMinimum(1);
    gusSB->setMinimum(1);
    gusSB->setMaximum(3);

    QGridLayout* mainLayout = new QGridLayout; // виджет компоновщие

    gusControl->setText("Управление гусеницами:\n              W A S D"); // текст с описанием
    handsControl->setText("Управление руками:\n             T F G H");
    cumControl->setText("Управление камеров:\n              I J K L");
    sens->setText("Чуствительность");
    cum->setText("Камера");
    gus->setText("Гусеницы");

    QRadioButton* autoButton = new QRadioButton("Авто"); // кнопки выбора режима управления
    QRadioButton* notAutoButton = new QRadioButton("Ручной");

    notAutoButton->setChecked(true); // стартовое значение радиокнопки

    mainLayout->addWidget(autoButton, 1, 11, 1, 2); // компоновка элементов
    mainLayout->addWidget(notAutoButton, 2, 11, 1, 2);
    mainLayout->addWidget(sens, 1, 1, 1, 2, Qt::AlignCenter);
    mainLayout->addWidget(cum, 3, 0, Qt::AlignCenter);
    mainLayout->addWidget(gus, 2, 0, Qt::AlignCenter);
    mainLayout->addWidget(tempScreen, 0, 4, 4, 6);
    mainLayout->addWidget(gusSB, 2, 1, 1, 2, Qt::AlignCenter);
    mainLayout->addWidget(cumSB, 3, 1, 1, 2, Qt::AlignCenter);
    mainLayout->addWidget(gusControl, 4, 1, 3, 3, Qt::AlignCenter);
    mainLayout->addWidget(handsControl, 4, 5, 3, 3, Qt::AlignCenter);
    mainLayout->addWidget(cumControl, 4, 9, 3, 3, Qt::AlignCenter);
    mainLayout->addWidget(CBw, 6, 3, Qt::AlignCenter);
    mainLayout->addWidget(CBa, 7, 2, Qt::AlignCenter);
    mainLayout->addWidget(CBs, 7, 3, Qt::AlignCenter);
    mainLayout->addWidget(CBd, 7, 4, Qt::AlignCenter);
    mainLayout->addWidget(CBt, 6, 6, Qt::AlignCenter);
    mainLayout->addWidget(CBf, 7, 5, Qt::AlignCenter);
    mainLayout->addWidget(CBg, 7, 6, Qt::AlignCenter);
    mainLayout->addWidget(CBh, 7, 7, Qt::AlignCenter);
    mainLayout->addWidget(CBi, 6, 9, Qt::AlignCenter);
    mainLayout->addWidget(CBj, 7, 8, Qt::AlignCenter);
    mainLayout->addWidget(CBk, 7, 9, Qt::AlignCenter);
    mainLayout->addWidget(CBl, 7, 10, Qt::AlignCenter);

    setLayout(mainLayout); //  установка менеджера компоновки в виджет
}

void WnControl::keyPressEvent(QKeyEvent *pe) // метод обработки нажатия на клавиши
{
    qDebug() << pe->key();
    switch (pe->key()){ // в зависимости от выбранной кнопки меняется значение чекбокса
    case Qt::Key_W :
    {
        CBw->setChecked(true);
        myClient->pressButton(QString(Qt::Key_W));
        break;
    }
    case Qt::Key_A :
    {
        CBa->setChecked(true);
        myClient->pressButton(QString(Qt::Key_A));
        break;
    }
    case Qt::Key_S :
    {
        CBs->setChecked(true);
        myClient->pressButton(QString(Qt::Key_S));
        break;
    }
    case Qt::Key_D :
    {
        CBd->setChecked(true);
        myClient->pressButton(QString(Qt::Key_D));
        break;
    }
    case Qt::Key_T :
    {
        CBt->setChecked(true);
        myClient->pressButton(QString(Qt::Key_T));
        break;
    }
    case Qt::Key_F :
    {
        CBf->setChecked(true);
        myClient->pressButton(QString(Qt::Key_F));
        break;
    }
    case Qt::Key_G :
    {
        CBg->setChecked(true);
        myClient->pressButton(QString(Qt::Key_G));
        break;
    }
    case Qt::Key_H :
    {
        CBh->setChecked(true);
        myClient->pressButton(QString(Qt::Key_H));
        break;
    }
    case Qt::Key_I :
    {
        CBi->setChecked(true);
        myClient->pressButton(QString(Qt::Key_A));
        break;
    }
    case Qt::Key_J :
    {
        CBj->setChecked(true);
        myClient->pressButton(QString(Qt::Key_J));
        break;
    }
    case Qt::Key_K :
    {
        CBk->setChecked(true);
        myClient->pressButton(QString(Qt::Key_K));
        break;
    }
    case Qt::Key_L :
    {
        CBl->setChecked(true);
        myClient->pressButton(QString(Qt::Key_L));
        break;
    }
    case Qt::Key_Escape :
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(nullptr, "Warning", "Закрыть приложение?", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes)
            QApplication::quit();
        break;
    }
    }
}

void WnControl::keyReleaseEvent(QKeyEvent *pe) // метод обработки нажатия на клавиши
{
    switch(pe->key()) { // в зависимости от выбранной кнопки меняется значение чекбокса
    case Qt::Key_W :
        CBw->setChecked(false);
        break;
    case Qt::Key_A :
        CBa->setChecked(false);
        break;
    case Qt::Key_S :
        CBs->setChecked(false);
        break;
    case Qt::Key_D :
        CBd->setChecked(false);
        break;
    case Qt::Key_T :
        CBt->setChecked(false);
        break;
    case Qt::Key_F :
        CBf->setChecked(false);
        break;
    case Qt::Key_G :
        CBg->setChecked(false);
        break;
    case Qt::Key_H :
        CBh->setChecked(false);
        break;
    case Qt::Key_I :
        CBi->setChecked(false);
        break;
    case Qt::Key_J :
        CBj->setChecked(false);
        break;
    case Qt::Key_K :
        CBk->setChecked(false);
        break;
    case Qt::Key_L :
        CBl->setChecked(false);
        break;
    }
}
