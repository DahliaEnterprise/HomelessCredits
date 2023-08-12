#ifndef SOLO_VENTANA_H
#define SOLO_VENTANA_H

#include "solo_ventana_lista_de_botones.h"
#include <QWidget>
#include <QBoxLayout>
#include <QDebug>

class solo_ventana : public QWidget
{
    Q_OBJECT
public:
    explicit solo_ventana(QWidget *parent = nullptr);
    void inicializar();

private:
    solo_ventana_lista_de_botones * lista_de_botones;
    QBoxLayout * layout;

signals:

public slots:
    void boton_presionado(QString button_title);

};

#endif // SOLO_VENTANA_H
