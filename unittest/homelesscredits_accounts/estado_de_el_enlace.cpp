#include "estado_de_el_enlace.h"

estado_de_el_enlace::estado_de_el_enlace(QObject *parent)
    : QObject{parent}
{

}

void estado_de_el_enlace::inicializar()
{

}

void estado_de_el_enlace::mensaje_de_proceso(QByteArray mensaje_a_procesar)
{
    qDebug() << ": " << mensaje_a_procesar;
}
