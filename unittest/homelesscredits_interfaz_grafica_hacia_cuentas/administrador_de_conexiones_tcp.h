#ifndef ADMINISTRADOR_DE_CONEXIONES_TCP_H
#define ADMINISTRADOR_DE_CONEXIONES_TCP_H

#include "el_trabajador_genera_un_resultado_relacionado_con_la_funcion_de_otacion.h"

#include <QObject>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QThread>

class administrador_de_conexiones_tcp : public QObject
{
    Q_OBJECT
public:
    explicit administrador_de_conexiones_tcp(QObject *parent = nullptr);
    void inicializar();
    void conectarse_al_servidor_de_contabilidad();

private:
    QTcpSocket * controlador_de_conexion_tcp;
    el_trabajador_genera_un_resultado_relacionado_con_la_funcion_de_otacion * trabajador;
    QThread trabajador_identificador;

signals:

};

#endif // ADMINISTRADOR_DE_CONEXIONES_TCP_H
