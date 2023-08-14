#ifndef ESTADO_DE_EL_ENLACE_H
#define ESTADO_DE_EL_ENLACE_H

#include <QObject>
#include <QDebug>

class estado_de_el_enlace : public QObject
{
    Q_OBJECT
public:
    explicit estado_de_el_enlace(QObject *parent = nullptr);
    void inicializar();
    void mensaje_de_proceso(QByteArray mensaje_a_procesar);

signals:

};

#endif // ESTADO_DE_EL_ENLACE_H
