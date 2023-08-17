#include "estado_de_el_enlace.h"

estado_de_el_enlace::estado_de_el_enlace(QObject *parent)
    : QObject{parent}
{

}

void estado_de_el_enlace::inicializar(QTcpSocket * enchufe, QByteArray establecer_identificador_de_encapsulacion)
{
    enchufe_asociado = enchufe;
    encapsulacion_identificador = establecer_identificador_de_encapsulacion;
    identificador_de_proceso = new subproceso_de_trabajo_sobre_el_procesamiento_de_mensajes();
    identificador_de_proceso->inicializar();
        //señales y ranuras con respecto al procesamiento de mensajes
            //establecer el ciclo de conexión
            QObject::connect(this, SIGNAL(enviar_a_subproceso_con_respecto_al_establecimiento_de_una_conexion()), identificador_de_proceso, SLOT(establecer_conexion()));
            QObject::connect(identificador_de_proceso, SIGNAL(resultados_de_la_solicitud_de_establecer_conexion(QByteArray)), this, SLOT(manejar_la_respuesta_con_respecto_al_establecimiento_de_la_conexion(QByteArray)));

    identificador_de_proceso->moveToThread(&subproceso_de_trabajo);
    subproceso_de_trabajo.start();

}


void estado_de_el_enlace::mensaje_de_proceso(QByteArray mensaje_a_procesar)
{

    //hacer
    //If(mensaje_a_procesar == "acción"){ //trabajo }

    //se recibió el mensaje de establecer conexión
    emit enviar_a_subproceso_con_respecto_al_establecimiento_de_una_conexion();

}


void estado_de_el_enlace::manejar_la_respuesta_con_respecto_al_establecimiento_de_la_conexion(QByteArray respuesta)
{
    //send to tcp connection
    QString paquete_para_enviar = QString();
    paquete_para_enviar.append(encapsulacion_identificador);
    paquete_para_enviar.append(respuesta);
    paquete_para_enviar.append(encapsulacion_identificador);
    enchufe_asociado->write(paquete_para_enviar.toUtf8());
}
