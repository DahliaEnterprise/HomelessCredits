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
}

void solo_ventana::boton_presionado(QString titulo_de_boton)
{
    qDebug() << titulo_de_boton;
}
