#include "wnadmin.h"

WnAdmin::WnAdmin(QWidget* parent): QWidget(parent)
{
    setFixedSize(900, 900);
    QTextEdit* console = new QTextEdit;

    console->resize(900, 900);

    QGridLayout* Gl = new QGridLayout;

    Gl->addWidget(console, 0, 0, 3, 5);

    setLayout(Gl);

}
