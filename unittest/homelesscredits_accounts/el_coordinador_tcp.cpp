#include "el_coordinador_tcp.h"

el_coordinador_tcp::el_coordinador_tcp(QObject *parent)
    : QObject{parent}
{

}

void el_coordinador_tcp::inicializar()
{
    encapsulacion_identificador = QByteArray("7d5f44727224662a5062623522356076");

    lista_de_buferes_asociativos = new QHash<QTcpSocket *, bufer_de_un_mensaje *>();
    lista_de_estado_de_enlace_asociativo = new QHash<QTcpSocket *, estado_de_el_enlace *>();
    directorio_de_transacciones = new pila_de_transacciones_compiladas();
    directorio_de_transacciones->inicializar();
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
        nuevo_bufer->inicializar(encapsulacion_identificador);

            //Make association
            lista_de_buferes_asociativos->insert(proximo_conexion, nuevo_bufer);

        estado_de_el_enlace * enlace_de_referencia = new estado_de_el_enlace();
        enlace_de_referencia->inicializar(proximo_conexion, encapsulacion_identificador, directorio_de_transacciones);

            //Make association
            lista_de_estado_de_enlace_asociativo->insert(proximo_conexion, enlace_de_referencia);

        lista_de_conexcion_tcp->append(proximo_conexion);
        QObject::connect(proximo_conexion, SIGNAL(readyRead()), this, SLOT(ready_read()));
    }
}



void el_coordinador_tcp::ready_read()
{
    QTcpSocket * socket = qobject_cast<QTcpSocket *>(sender());
    if(socket)
    {
         QByteArray data = socket->readAll();
         // Process the received data
         bufer_de_un_mensaje * bufer = lista_de_buferes_asociativos->value(socket);
         bufer->anadir_al_bufer(data);

         //check if there is an entire message arrived
         int  mensajes_totales = bufer->obtener_el_total_de_mensajes_disponibles();
         if(mensajes_totales > 0)
         {
             //Process next message
             estado_de_el_enlace * enlace_de_referencia = lista_de_estado_de_enlace_asociativo->value(socket);
             QByteArray bufer_temporal = QByteArray(bufer->obtener_el_siguiente_mensaje());
             qDebug() << bufer_temporal;
             bufer->eliminar_el_mensaje_completo_mas_reciente();
             enlace_de_referencia->mensaje_de_proceso(bufer_temporal);
         }
    }
}
