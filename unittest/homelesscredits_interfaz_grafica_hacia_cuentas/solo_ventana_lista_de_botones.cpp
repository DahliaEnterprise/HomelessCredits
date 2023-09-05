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

    boton_generar_clave = new QPushButton();
    boton_generar_clave->setText(QString("Generar clave"));
    layout->addWidget(boton_generar_clave, 1, Qt::AlignCenter);

    QObject::connect(boton_conectar, SIGNAL(pressed()), this, SLOT(pressed_conectar()));
    QObject::connect(boton_generar_clave, SIGNAL(pressed()), this, SLOT(pressed_generar_clave()));
    this->setLayout(layout);


}

void solo_ventana_lista_de_botones::pressed_conectar()
{
    emit button_has_been_pressed("Conectar a la Gestion de Cuentas");
}

void solo_ventana_lista_de_botones::pressed_generar_clave()
{
    qDebug() << "presed";
    emit button_has_been_pressed("Generar clave");
}
