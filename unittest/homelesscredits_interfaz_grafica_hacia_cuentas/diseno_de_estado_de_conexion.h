#ifndef DISENO_DE_ESTADO_DE_CONEXION_H
#define DISENO_DE_ESTADO_DE_CONEXION_H

#include <QWidget>
#include <QBoxLayout>
#include <QLabel>

class diseno_de_estado_de_conexion : public QWidget
{
    Q_OBJECT
public:
    explicit diseno_de_estado_de_conexion(QWidget *parent = nullptr);
    void inicializar();
    void coloca_una_etiqueta(QString texto);

private:
    QBoxLayout * layout;
    QLabel * etiqueta_sobre_el_estado_de_la_conexion;

signals:

};

#endif // DISENO_DE_ESTADO_DE_CONEXION_H
