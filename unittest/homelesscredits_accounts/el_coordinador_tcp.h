#ifndef EL_COORDINADOR_TCP_H
#define EL_COORDINADOR_TCP_H

#include "bufer_de_un_mensaje.h"
#include "estado_de_el_enlace.h"
#include "pila_de_transacciones_compiladas.h"

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QHash>

class el_coordinador_tcp : public QObject
{
    Q_OBJECT
public:
    explicit el_coordinador_tcp(QObject *parent = nullptr);
    void inicializar();

private:
    QTcpServer * server;
    QVector<QTcpSocket*> * lista_de_conexcion_tcp;
    QHash<QTcpSocket *, bufer_de_un_mensaje *> * lista_de_buferes_asociativos;
    QHash<QTcpSocket *, estado_de_el_enlace *> * lista_de_estado_de_enlace_asociativo;
    pila_de_transacciones_compiladas * directorio_de_transacciones;
    QByteArray encapsulacion_identificador;


signals:

private slots:
    void new_connection();
    void ready_read();
};

#endif // EL_COORDINADOR_TCP_H
