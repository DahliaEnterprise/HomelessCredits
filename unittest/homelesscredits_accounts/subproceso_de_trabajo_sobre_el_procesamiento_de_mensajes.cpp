 #include "subproceso_de_trabajo_sobre_el_procesamiento_de_mensajes.h"

subproceso_de_trabajo_sobre_el_procesamiento_de_mensajes::subproceso_de_trabajo_sobre_el_procesamiento_de_mensajes(QObject *parent)
    : QObject{parent}
{

}

void subproceso_de_trabajo_sobre_el_procesamiento_de_mensajes::inicializar(int * definir_conectado_al_servicio)
{
    //padre_conectado_al_servicio = definir_conectado_al_servicio;
}

void subproceso_de_trabajo_sobre_el_procesamiento_de_mensajes::establecer_conexion()
{

    QJsonObject jobj;
    jobj.insert(QString("response"), QJsonValue(QString("connected")));

    //
    //padre_conectado_al_servicio = (int*)1;

    emit resultados_de_la_solicitud_de_establecer_conexion(jobj);
}
