#ifndef ADMINISTRADOR_DE_CONEXIONES_TCP_H
#define ADMINISTRADOR_DE_CONEXIONES_TCP_H

#include <QObject>
#include <QTcpSocket>

class administrador_de_conexiones_tcp : public QObject
{
    Q_OBJECT
public:
    explicit administrador_de_conexiones_tcp(QObject *parent = nullptr);
    void inicializar();
    void conectarse_al_servidor_de_contabilidad();

private:
    QTcpSocket * controlador_de_conexion_tcp;

signals:

};

#endif // ADMINISTRADOR_DE_CONEXIONES_TCP_H
