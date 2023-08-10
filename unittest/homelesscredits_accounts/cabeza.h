#ifndef CABEZA_H
#define CABEZA_H

#include <QObject>
#include "el_coordinador_tcp.h"

class cabeza : public QObject
{
    Q_OBJECT
public:
    explicit cabeza(QObject *parent = nullptr);
    void inicializar();

private:
    el_coordinador_tcp * coordinador_tcp;

signals:

};

#endif // CABEZA_H
