#include "pila_de_transacciones_compiladas.h"

pila_de_transacciones_compiladas::pila_de_transacciones_compiladas(QObject *parent)
    : QObject{parent}
{

}

void pila_de_transacciones_compiladas::inicializar()
{
    transaccions = new QHash<qint32, QJsonObject>();

}

void pila_de_transacciones_compiladas::obtener_el_carpeta_mas_reciente_de_transacciones()
{

}
