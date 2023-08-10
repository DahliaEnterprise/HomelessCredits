#include <QCoreApplication>
#include "cabeza.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cabeza * primero = new cabeza();
    primero->inicializar();

    return a.exec();
}
