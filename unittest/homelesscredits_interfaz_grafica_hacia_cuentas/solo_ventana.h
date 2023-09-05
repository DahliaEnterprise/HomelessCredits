#ifndef SOLO_VENTANA_H
#define SOLO_VENTANA_H

#include "solo_ventana_lista_de_botones.h"
#include "pagina/diseno_de_estado_de_conexion.h"
#include "administrador_de_conexiones_tcp.h"
#include "gestion_criptica/clave_gerente.h"

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
    administrador_de_conexiones_tcp * lista_de_conexiones;
    solo_ventana_lista_de_botones * lista_de_botones;
    diseno_de_estado_de_conexion * estado_de_conexion;
    clave_gerente * identificador_clave_gerente;
    QBoxLayout * layout;

signals:

public slots:
    void boton_presionado(QString button_title);

};

#endif // SOLO_VENTANA_H
