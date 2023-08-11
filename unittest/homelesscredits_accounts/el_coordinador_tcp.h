#ifndef EL_COORDINADOR_TCP_H
#define EL_COORDINADOR_TCP_H

#include <QObject>
#include <QTcpServer>
#include <QVector>

class el_coordinador_tcp : public QObject
{
    Q_OBJECT
public:
    explicit el_coordinador_tcp(QObject *parent = nullptr);
    void inicializar();

private:
    QTcpServer * server;
    QVector<QTcpSocket*> * lista_de_conexcion_tcp;

signals:

private slots:
    void new_connection();
};

#endif // EL_COORDINADOR_TCP_H
