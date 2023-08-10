#include "cabeza.h"

cabeza::cabeza(QObject *parent)
    : QObject{parent}
{

}

void cabeza::inicializar()
{
    coordinador_tcp = new el_coordinador_tcp();
    coordinador_tcp->inicializar();
}
