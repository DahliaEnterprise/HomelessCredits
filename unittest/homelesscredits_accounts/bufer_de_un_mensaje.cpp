#include "bufer_de_un_mensaje.h"

bufer_de_un_mensaje::bufer_de_un_mensaje(QObject *parent)
    : QObject{parent}
{

}

void bufer_de_un_mensaje::inicializar(QByteArray establecer_encapsulacion_identificador)
{
    encapsulacion_identificador.clear();
    encapsulacion_identificador.append(establecer_encapsulacion_identificador);

}

void bufer_de_un_mensaje::anadir_al_bufer(QByteArray datos_entrantes)
{
    bufer.append(datos_entrantes);
    QString datos_como_cadena = QString::fromUtf8(datos_entrantes);
    int identificadores_de_encapsulacion_total = datos_como_cadena.count(QString::fromUtf8(encapsulacion_identificador));
    int mensajes_nuevos_totales = qFloor((identificadores_de_encapsulacion_total / 2));
    mensajes_totales = mensajes_nuevos_totales;
}


int bufer_de_un_mensaje::obtener_el_total_de_mensajes_disponibles()
{
    return mensajes_totales;
}

QByteArray bufer_de_un_mensaje::obtener_el_siguiente_mensaje()
{
    QString amortiguador_como_bufer = QString::fromStdString(bufer.toStdString());
    QStringList lista_de_mensajes = amortiguador_como_bufer.split(encapsulacion_identificador);
    int fondo_indexado = -1;
    int indice = 0;
    while(indice < lista_de_mensajes.size())
    {
        if(lista_de_mensajes.at(indice).size() != 0)
        {
            fondo_indexado = indice;
            indice = lista_de_mensajes.size();
        }else{
            indice = indice + 1;
        }
    }

    return lista_de_mensajes.at(fondo_indexado).toUtf8();
}

void bufer_de_un_mensaje::eliminar_el_mensaje_completo_mas_reciente()
{
    //Detectar que existe un mensaje completo
    if(mensajes_totales > 0)
    {
        //Eliminar el mensaje y el encapsulado
        int start_index = bufer.indexOf(encapsulacion_identificador, 0);
        int end_index = bufer.indexOf(encapsulacion_identificador, (start_index + encapsulacion_identificador.length()));
        end_index = end_index + encapsulacion_identificador.length();
        bufer = bufer.remove(start_index, (end_index - start_index));

        qDebug() << "bufer1:" << bufer;
    }
}

