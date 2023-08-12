#include "solo_ventana.h"

solo_ventana::solo_ventana(QWidget *parent)
    : QWidget{parent}
{

}

void solo_ventana::inicializar()
{
    this->setWindowTitle("Acceso a la gestion contable");
    lisa_de_botones = new solo_ventana_lista_de_botones();
}
