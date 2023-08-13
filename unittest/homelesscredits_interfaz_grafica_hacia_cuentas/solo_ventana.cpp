#include "solo_ventana.h"

solo_ventana::solo_ventana(QWidget *parent)
    : QWidget{parent}
{

}

void solo_ventana::inicializar()
{
    this->setWindowTitle("Acceso a la gestion contable");
    layout = new QBoxLayout(QBoxLayout::TopToBottom, nullptr);
        lista_de_botones = new solo_ventana_lista_de_botones();
        lista_de_botones->inicializar();
        layout->addWidget(lista_de_botones, 1, Qt::AlignHCenter);
        QObject::connect(lista_de_botones, SIGNAL(button_has_been_pressed(QString)), this, SLOT(boton_presionado(QString)));
        this->setLayout(layout);

        estado_de_conexion = new diseno_de_estado_de_conexion();
        estado_de_conexion->inicializar();
        estado_de_conexion->hide();
        layout->addWidget(estado_de_conexion);

    lista_de_conexiones = new administrador_de_conexiones_tcp();
    lista_de_conexiones->inicializar();
}

void solo_ventana::boton_presionado(QString titulo_de_boton)
{
    if(titulo_de_boton.compare("Conectar a la Gestion de Cuentas") == 0)
    {
        lista_de_botones->hide();
        estado_de_conexion->show();
        lista_de_conexiones->conectarse_al_servidor_de_contabilidad();
    }
}
