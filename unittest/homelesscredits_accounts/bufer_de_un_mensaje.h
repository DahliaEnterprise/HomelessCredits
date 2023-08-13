#ifndef BUFER_DE_UN_MENSAJE_H
#define BUFER_DE_UN_MENSAJE_H

#include <QObject>

class bufer_de_un_mensaje : public QObject
{
    Q_OBJECT
public:
    explicit bufer_de_un_mensaje(QObject *parent = nullptr);
    void inicializar();

signals:

};

#endif // BUFER_DE_UN_MENSAJE_H
