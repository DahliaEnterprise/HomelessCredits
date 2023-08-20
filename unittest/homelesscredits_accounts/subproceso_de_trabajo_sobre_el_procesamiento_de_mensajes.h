#ifndef SUBPROCESO_DE_TRABAJO_SOBRE_EL_PROCESAMIENTO_DE_MENSAJES_H
#define SUBPROCESO_DE_TRABAJO_SOBRE_EL_PROCESAMIENTO_DE_MENSAJES_H

#include "pila_de_transacciones_compiladas.h"

#include <QObject>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>

class subproceso_de_trabajo_sobre_el_procesamiento_de_mensajes : public QObject
{
    Q_OBJECT
public:
    explicit subproceso_de_trabajo_sobre_el_procesamiento_de_mensajes(QObject *parent = nullptr);
    void inicializar(int * definir_conectado_al_servicio,  pila_de_transacciones_compiladas * establecer_identificador_para_transacciones_compiladas);

private:
    //int * padre_conectado_al_servicio;
    pila_de_transacciones_compiladas * identificador_para_transacciones_compiladas;

public slots:
    void establecer_conexion();
    void adquirir_la_carpeta_de_transacciones_mas_reciente(QByteArray mensaje_a_procesar);

signals:
    void resultados_de_la_solicitud_de_establecer_conexion(QJsonObject result);
};

#endif // SUBPROCESO_DE_TRABAJO_SOBRE_EL_PROCESAMIENTO_DE_MENSAJES_H
