#include "estado_de_el_enlace.h"

estado_de_el_enlace::estado_de_el_enlace(QObject *parent)
    : QObject{parent}
{

}

void estado_de_el_enlace::inicializar(QTcpSocket * enchufe, QByteArray establecer_identificador_de_encapsulacion)
{
    //inicializar
    conectado_al_servicio = 0;

    //
    enchufe_asociado = enchufe;
    encapsulacion_identificador = establecer_identificador_de_encapsulacion;
    identificador_de_proceso = new subproceso_de_trabajo_sobre_el_procesamiento_de_mensajes();
    identificador_de_proceso->inicializar(&conectado_al_servicio);
        //señales y ranuras con respecto al procesamiento de mensajes
            //establecer el ciclo de conexión
            QObject::connect(this, SIGNAL(enviar_a_subproceso_con_respecto_al_establecimiento_de_una_conexion()), identificador_de_proceso, SLOT(establecer_conexion()));
            QObject::connect(identificador_de_proceso, SIGNAL(resultados_de_la_solicitud_de_establecer_conexion(QJsonObject)), this, SLOT(manejar_la_respuesta_con_respecto_al_establecimiento_de_la_conexion(QJsonObject)));

    identificador_de_proceso->moveToThread(&subproceso_de_trabajo);
    subproceso_de_trabajo.start();
}


void estado_de_el_enlace::mensaje_de_proceso(QByteArray mensaje_a_procesar)
{

    //hacer
    //If(mensaje_a_procesar == "acción"){ //trabajo }
    //conectado_al_servicio = 4;
    //se recibió el mensaje de establecer conexión
    QJsonDocument jdoc = QJsonDocument::fromJson(mensaje_a_procesar, nullptr);
    QJsonObject jobj = jdoc.object();
    QString solicitar_value = jobj.value("solicitar").toString();
    if(solicitar_value.compare("establecer_conexion") == 0)
    {
        emit enviar_a_subproceso_con_respecto_al_establecimiento_de_una_conexion();
    }else if(solicitar_value.compare("el_carpeta_de_transacciones_mas_reciente") == 0)
    {
        //TODO emit enviar a subproceso con respecto al carpeta de transacciones mas reciente
    }

}


void estado_de_el_enlace::manejar_la_respuesta_con_respecto_al_establecimiento_de_la_conexion(QJsonObject respuesta)
{

    QJsonDocument respuesta_jdoc = QJsonDocument(respuesta);

qDebug() << "conexion texto";
    //send to tcp connection
    QString paquete_para_enviar = QString();
    paquete_para_enviar.append(encapsulacion_identificador);
    paquete_para_enviar.append(respuesta_jdoc.toJson(QJsonDocument::Compact));
    paquete_para_enviar.append(encapsulacion_identificador);
    enchufe_asociado->write(paquete_para_enviar.toUtf8());
}
