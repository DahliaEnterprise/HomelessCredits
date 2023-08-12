#ifndef SOLO_VENTANA_H
#define SOLO_VENTANA_H

#include "ventana_solo_de_clases/solo_ventana_lista_de_botones.h"
#include <QWidget>

class solo_ventana : public QWidget
{
    Q_OBJECT
public:
    explicit solo_ventana(QWidget *parent = nullptr);
    void inicializar();

private:
    solo_ventana_lista_de_botones * lista_de_botones;

signals:

};

#endif // SOLO_VENTANA_H
