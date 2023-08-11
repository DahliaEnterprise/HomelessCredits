#include "el_coordinador_tcp.h"

el_coordinador_tcp::el_coordinador_tcp(QObject *parent)
    : QObject{parent}
{

}

void el_coordinador_tcp::inicializar()
{
    lista_de_conexcion_tcp = new QVector<QTcpSocket*>();

    server = new QTcpServer();
    QObject::connect(server, SIGNAL(newConnection()), this, SLOT(new_connection()));
    server->listen(QHostAddress::AnyIPv4, 8080);

}

void el_coordinador_tcp::new_connection()
{
    QTcpSocket * next_connection = server->nextPendingConnection();
    if(next_connection != nullptr)
    {
        lista_de_conexcion_tcp->append(next_connection);
    }
}
