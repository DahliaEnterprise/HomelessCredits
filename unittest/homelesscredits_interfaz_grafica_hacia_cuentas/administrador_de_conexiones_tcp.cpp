#include "administrador_de_conexiones_tcp.h"

administrador_de_conexiones_tcp::administrador_de_conexiones_tcp(QObject *parent)
    : QObject{parent}
{

}

void administrador_de_conexiones_tcp::inicializar()
{
    controlador_de_conexion_tcp = new QTcpSocket();

}

void administrador_de_conexiones_tcp::conectarse_al_servidor_de_contabilidad()
{
    controlador_de_conexion_tcp->connectToHost(QString("127.0.0.1"), 8080);
    controlador_de_conexion_tcp->waitForConnected();
    controlador_de_conexion_tcp->write(QByteArray("Test message\n"));
}
