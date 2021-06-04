#include "tabWidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MyTabWidget tab(nullptr); // создаем виджет с прокруиваемыми окнами

    tab.show();

    return app.exec();
}
