#ifndef BUFER_DE_UN_MENSAJE_H
#define BUFER_DE_UN_MENSAJE_H

#include <QObject>
#include <QByteArray>
#include <QDebug>
#include <QtMath>
#include <QMap>

class bufer_de_un_mensaje : public QObject
{
    Q_OBJECT
public:
    explicit bufer_de_un_mensaje(QObject *parent = nullptr);
    void inicializar(QByteArray establecer_encapsulacion_identificador);
    void anadir_al_bufer(QByteArray datos_entrantes);
    int obtener_el_total_de_mensajes_disponibles();
    QByteArray obtener_el_siguiente_mensaje();
    void eliminar_el_mensaje_completo_mas_reciente();

private:
    QByteArray encapsulacion_identificador;
    QByteArray bufer;
    int mensajes_totales;

signals:

};

#endif // BUFER_DE_UN_MENSAJE_H
