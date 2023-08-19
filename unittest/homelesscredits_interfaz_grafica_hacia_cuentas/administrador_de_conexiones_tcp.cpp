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
    //conexion tcp a la manguera
    controlador_de_conexion_tcp->connectToHost(QString("127.0.0.1"), 8080);
    controlador_de_conexion_tcp->waitForConnected();

    //establecer la presencia del protocolo solicitando un protocolo
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

    controlador_de_conexion_tcp->waitForReadyRead();
    QByteArray respuesta = controlador_de_conexion_tcp->readAll();
    QString respuesta_de_protocolo = QString::fromUtf8(respuesta);
    respuesta_de_protocolo = respuesta_de_protocolo.replace("7d5f44727224662a5062623522356076", "");

    /*  determine si se ha establecido una presencia de protocolo (a través del reconocimiento) y,
     *  si eso es cierto, continúe con la determinación de la carpeta de transacciones más reciente.
     */

    //el respuesta sobre el estado de conexión del protocolo
    QJsonDocument jdoc_respuesta_como_cadena = QJsonDocument::fromJson(respuesta_de_protocolo.toUtf8());
    QJsonObject jobj_respuesta_como_cadena = jdoc_respuesta_como_cadena.object();
    qDebug() << jobj_respuesta_como_cadena;
}
