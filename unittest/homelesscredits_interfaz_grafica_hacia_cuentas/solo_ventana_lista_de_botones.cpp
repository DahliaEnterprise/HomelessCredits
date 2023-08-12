#include "solo_ventana_lista_de_botones.h"

solo_ventana_lista_de_botones::solo_ventana_lista_de_botones(QWidget *parent)
    : QWidget{parent}
{

}

void solo_ventana_lista_de_botones::inicializar()
{
    layout = new QBoxLayout(QBoxLayout::TopToBottom);
    boton_conectar = new QPushButton();
    boton_conectar->setText(QString("Concetar a la Gestion de Cuentas"));
    layout->addWidget(boton_conectar, 1, Qt::AlignCenter);

    QObject::connect(boton_conectar, SIGNAL(pressed()), this, SLOT(pressed_conectar()));
    this->setLayout(layout);
}

void solo_ventana_lista_de_botones::pressed_conectar()
{
    emit button_has_been_pressed("Conectar a la Gestion de Cuentas");
}
