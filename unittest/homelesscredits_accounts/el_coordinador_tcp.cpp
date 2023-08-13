#include "el_coordinador_tcp.h"

el_coordinador_tcp::el_coordinador_tcp(QObject *parent)
    : QObject{parent}
{

}

void el_coordinador_tcp::inicializar()
{
    lista_de_buferes_asociativos = new QHash<QTcpSocket *, bufer_de_un_mensaje *>();
    lista_de_conexcion_tcp = new QVector<QTcpSocket*>();

    server = new QTcpServer();
    QObject::connect(server, SIGNAL(newConnection()), this, SLOT(new_connection()));
    server->listen(QHostAddress::AnyIPv4, 8080);

}

void el_coordinador_tcp::new_connection()
{
    QTcpSocket * proximo_conexion = server->nextPendingConnection();
    if(proximo_conexion != nullptr)
    {
        //Create an associative buffer to also associate with this connections.
        bufer_de_un_mensaje * nuevo_bufer = new bufer_de_un_mensaje();
        nuevo_bufer->inicializar();

        //Make association
        lista_de_buferes_asociativos->insert(proximo_conexion, nuevo_bufer);

        lista_de_conexcion_tcp->append(proximo_conexion);
        QObject::connect(proximo_conexion, SIGNAL(readyRead()), this, SLOT(ready_read()));
    }
}

void el_coordinador_tcp::ready_read()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if(socket)
    {
         QByteArray data = socket->readAll();
         // Process the received data
         qDebug() << data;
    }
}
