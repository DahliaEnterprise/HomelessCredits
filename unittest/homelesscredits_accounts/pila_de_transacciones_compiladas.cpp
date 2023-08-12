#include "pila_de_transacciones_compiladas.h"

pila_de_transacciones_compiladas::pila_de_transacciones_compiladas(QObject *parent)
    : QObject{parent}
{

}

void pila_de_transacciones_compiladas::inicializar()
{
    transaccions = new QHash<qint32, QJsonObject>();

}
