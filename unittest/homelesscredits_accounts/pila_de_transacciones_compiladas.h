#ifndef PILA_DE_TRANSACCIONES_COMPILADAS_H
#define PILA_DE_TRANSACCIONES_COMPILADAS_H

#include <QObject>
#include <QHash>
#include <QJsonObject>

class pila_de_transacciones_compiladas : public QObject
{
    Q_OBJECT
public:
    explicit pila_de_transacciones_compiladas(QObject *parent = nullptr);
    void inicializar();

private:
    QHash<qint32, QJsonObject> * transaccions;


signals:

};

#endif // PILA_DE_TRANSACCIONES_COMPILADAS_H
