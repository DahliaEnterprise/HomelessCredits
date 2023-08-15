#ifndef ESTADO_DE_EL_ENLACE_H
#define ESTADO_DE_EL_ENLACE_H

#include "subproceso_de_trabajo_sobre_el_procesamiento_de_mensajes.h"

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QTcpSocket>

class estado_de_el_enlace : public QObject
{
    Q_OBJECT
public:
    explicit estado_de_el_enlace(QObject *parent = nullptr);
    void inicializar(QTcpSocket * enchufe, QByteArray establecer_identificador_de_encapsulacion);
    void mensaje_de_proceso(QByteArray mensaje_a_procesar);

private:
    subproceso_de_trabajo_sobre_el_procesamiento_de_mensajes * identificador_de_proceso;
    QThread subproceso_de_trabajo;
    QTcpSocket * enchufe_asociado; //esto se define fuera de esta clase en particular
    QByteArray encapsulacion_identificador;

public slots:
    void manejar_la_respuesta_con_respecto_al_establecimiento_de_la_conexion(QByteArray respuesta);

signals:
    void enviar_a_subproceso_con_respecto_al_establecimiento_de_una_conexion();

};

#endif // ESTADO_DE_EL_ENLACE_H
