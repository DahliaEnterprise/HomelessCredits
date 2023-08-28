#ifndef CLAVE_GERENTE_H
#define CLAVE_GERENTE_H

#include <QObject>
#include <iostream>
#include <openssl/ssl.h>
#include <openssl/crypto.h>


class clave_gerente : public QObject
{
    Q_OBJECT
public:
    explicit clave_gerente(QObject *parent = nullptr);
    void clave_nuevo();

signals:

};

#endif // CLAVE_GERENTE_H
