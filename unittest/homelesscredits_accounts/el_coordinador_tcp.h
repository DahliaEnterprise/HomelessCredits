#ifndef EL_COORDINADOR_TCP_H
#define EL_COORDINADOR_TCP_H

#include <QObject>

class el_coordinador_tcp : public QObject
{
    Q_OBJECT
public:
    explicit el_coordinador_tcp(QObject *parent = nullptr);
    void inicializar();

signals:

};

#endif // EL_COORDINADOR_TCP_H
