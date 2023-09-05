#include "diseno_de_estado_de_conexion.h"

diseno_de_estado_de_conexion::diseno_de_estado_de_conexion(QWidget *parent)
    : QWidget{parent}
{

}

void diseno_de_estado_de_conexion::inicializar()
{
    layout = new QBoxLayout(QBoxLayout::TopToBottom, nullptr);
    this->setLayout(layout);

    etiqueta_sobre_el_estado_de_la_conexion = new QLabel(QString("Inicializando conexión"), nullptr);
    layout->addWidget(etiqueta_sobre_el_estado_de_la_conexion);
}

void diseno_de_estado_de_conexion::coloca_una_etiqueta(QString texto)
{
    etiqueta_sobre_el_estado_de_la_conexion->setText(texto);
}
