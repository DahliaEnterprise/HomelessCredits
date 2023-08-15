 #include "subproceso_de_trabajo_sobre_el_procesamiento_de_mensajes.h"

subproceso_de_trabajo_sobre_el_procesamiento_de_mensajes::subproceso_de_trabajo_sobre_el_procesamiento_de_mensajes(QObject *parent)
    : QObject{parent}
{

}

void subproceso_de_trabajo_sobre_el_procesamiento_de_mensajes::inicializar()
{

}

void subproceso_de_trabajo_sobre_el_procesamiento_de_mensajes::establecer_conexion()
{
    QJsonObject jobj;
    jobj.insert(QString("response"), QJsonValue(QString("connected")));
    QJsonDocument jdoc(jobj);

    emit resultados_de_la_solicitud_de_establecer_conexion(jdoc.toJson(QJsonDocument::Compact));
}
