#include "solo_ventana.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    solo_ventana * acceso = new solo_ventana();
    acceso->inicializar();
    acceso->show();

    return a.exec();
}
