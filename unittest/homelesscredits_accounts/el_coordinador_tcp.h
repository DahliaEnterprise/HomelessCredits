#ifndef EL_COORDINADOR_TCP_H
#define EL_COORDINADOR_TCP_H

#include "bufer_de_un_mensaje.h"

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

signals:

private slots:
    void new_connection();
    void ready_read();
};

#endif // EL_COORDINADOR_TCP_H
