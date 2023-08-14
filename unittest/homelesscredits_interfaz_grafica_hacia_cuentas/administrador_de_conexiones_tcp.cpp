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

    QJsonObject jobj;
    jobj.insert(QString("action"), QJsonValue("establish connection"));
    QJsonDocument * jdoc = new QJsonDocument();
    jdoc->setObject(jobj);
    QByteArray compact_bytearray = jdoc->toJson(QJsonDocument::Compact);
    QString mensaje = QString();
    mensaje.append("7d5f44727224662a5062623522356076");
    mensaje.append(QString("%1").arg(QString::fromUtf8(compact_bytearray)));
    mensaje.append("7d5f44727224662a5062623522356076");
    controlador_de_conexion_tcp->write(mensaje.toUtf8());


}
