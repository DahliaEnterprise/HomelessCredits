#ifndef ESTADO_DE_EL_ENLACE_H
#define ESTADO_DE_EL_ENLACE_H

#include "subproceso_de_trabajo_sobre_el_procesamiento_de_mensajes.h"
#include "pila_de_transacciones_compiladas.h"

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QTcpSocket>

class estado_de_el_enlace : public QObject
{
    Q_OBJECT
public:
    explicit estado_de_el_enlace(QObject *parent = nullptr);
    void inicializar(QTcpSocket * enchufe, QByteArray establecer_identificador_de_encapsulacion, pila_de_transacciones_compiladas * establecer_identificador_para_transacciones_compiladas);
    void mensaje_de_proceso(QByteArray mensaje_a_procesar);

private:
    subproceso_de_trabajo_sobre_el_procesamiento_de_mensajes * identificador_de_proceso;
    QThread subproceso_de_trabajo;
    QTcpSocket * enchufe_asociado; //esto se define fuera de esta clase en particular
    QByteArray encapsulacion_identificador;
    pila_de_transacciones_compiladas * identificador_para_transacciones_compiladas;

    //identificadores de estado de protocolo
    int conectado_al_servicio;

public slots:
    void manejar_la_respuesta_con_respecto_al_establecimiento_de_la_conexion(QJsonObject respuesta);

signals:
    void enviar_a_subproceso_con_respecto_al_establecimiento_de_una_conexion();
    void enviar_a_subproceso_con_respecto_al_carpeta_de_transacciones_mas_reciente(QByteArray);
};

#endif // ESTADO_DE_EL_ENLACE_H
