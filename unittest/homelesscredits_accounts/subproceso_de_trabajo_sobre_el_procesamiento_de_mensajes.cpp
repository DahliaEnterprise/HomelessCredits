 #include "subproceso_de_trabajo_sobre_el_procesamiento_de_mensajes.h"

subproceso_de_trabajo_sobre_el_procesamiento_de_mensajes::subproceso_de_trabajo_sobre_el_procesamiento_de_mensajes(QObject *parent)
    : QObject{parent}
{

}

void subproceso_de_trabajo_sobre_el_procesamiento_de_mensajes::inicializar(int * definir_conectado_al_servicio, pila_de_transacciones_compiladas * establecer_identificador_para_transacciones_compiladas)
{
    //padre_conectado_al_servicio = definir_conectado_al_servicio;
    identificador_para_transacciones_compiladas = establecer_identificador_para_transacciones_compiladas;
}

void subproceso_de_trabajo_sobre_el_procesamiento_de_mensajes::establecer_conexion()
{

    QJsonObject jobj;
    jobj.insert(QString("estado_de_respuesta"), QJsonValue(QString("conectado")));

    //
    //padre_conectado_al_servicio = (int*)1;

    emit resultados_de_la_solicitud_de_establecer_conexion(jobj);
}

void subproceso_de_trabajo_sobre_el_procesamiento_de_mensajes::adquirir_la_carpeta_de_transacciones_mas_reciente(QByteArray mensaje_a_procesar)
{

    QJsonObject jobj_resultados = identificador_para_transacciones_compiladas->obtener_el_carpeta_mas_reciente_de_transacciones();
    QJsonDocument jdoc = QJsonDocument();
    QJsonObject respuesta = QJsonObject();
    respuesta.insert(QString("reciente_carpeta_de_transacciones"), QJsonObject());
    jdoc.setObject(respuesta);

    emit resultado_sobre_carpeta_de_transacciones_recientes(respuesta);
}
