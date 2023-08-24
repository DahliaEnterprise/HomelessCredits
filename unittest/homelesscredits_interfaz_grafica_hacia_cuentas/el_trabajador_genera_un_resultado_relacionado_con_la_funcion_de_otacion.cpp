#include "el_trabajador_genera_un_resultado_relacionado_con_la_funcion_de_otacion.h"

el_trabajador_genera_un_resultado_relacionado_con_la_funcion_de_otacion::el_trabajador_genera_un_resultado_relacionado_con_la_funcion_de_otacion(QObject *parent)
    : QObject{parent}
{

}

void el_trabajador_genera_un_resultado_relacionado_con_la_funcion_de_otacion::generar_la_primera_carpeta()
{
    QJsonObject jobj = QJsonObject();

    jobj.insert(QString("accion"), QJsonValue(QString("primera_carpeta")));
    jobj.insert(QString("marcador_de_tiempo"), QJsonValue(QString("%1").arg(qFloor(QDateTime::currentMSecsSinceEpoch()/1000))));
    jobj.insert(QString("indice"), QJsonValue(QString("0")));
    jobj.insert(QString("nonce"), QJsonValue(QString("%1").arg()));

    emit resultado_sobre_carpeta_primeo_nuevo(jobj);
}
