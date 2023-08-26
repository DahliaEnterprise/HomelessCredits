#include "el_trabajador_genera_un_resultado_relacionado_con_la_funcion_de_otacion.h"

el_trabajador_genera_un_resultado_relacionado_con_la_funcion_de_otacion::el_trabajador_genera_un_resultado_relacionado_con_la_funcion_de_otacion(QObject *parent)
    : QObject{parent}
{

}

void el_trabajador_genera_un_resultado_relacionado_con_la_funcion_de_otacion::inicilizar()
{
    identificador_de_mapa = new mapa_de_datos_virtual_para_personas_sin_hogar();
    identificador_de_mapa->initialize_hash_function();
}

void el_trabajador_genera_un_resultado_relacionado_con_la_funcion_de_otacion::generar_la_primera_carpeta()
{
    int seguir = 1;
    while(seguir == 1)
    {
        //inicializar
        QJsonObject jobj = QJsonObject();
        qDebug() << "generating";
        //crear objeto json
        jobj.insert(QString("accion"), QJsonValue(QString("primera_carpeta")));
        jobj.insert(QString("marcador_de_tiempo"), QJsonValue(QString("%1").arg(qFloor(QDateTime::currentMSecsSinceEpoch()/1000))));
        jobj.insert(QString("indice"), QJsonValue(QString("0")));
        //nonce
        quint64 producir_un_resultado_alternativo = QRandomGenerator64::global()->generate64();
        jobj.insert(QString("nonce"), QJsonValue(QString("%1").arg(producir_un_resultado_alternativo)));

        //buscar diamante dentro de la geoda
        QJsonDocument jdoc = QJsonDocument();
        jdoc.setObject(jobj);
        QByteArray string_to_hash_as_qbytearray = jdoc.toJson(QJsonDocument::Compact);
        QString string_to_hash_as_qstring = QString::fromUtf8(string_to_hash_as_qbytearray);
        QString resultados = identificador_de_mapa->string_to_homelesscredits_hash(string_to_hash_as_qstring, 1000);
        int indice = 0;
        int detected_difficulty = 0;
        int current_difficulty = 2;
        while(indice < current_difficulty)
        {
            if(resultados.mid(resultados.length()-(indice + 1), 1).compare("0") == 0)
            {
                detected_difficulty = detected_difficulty + 1;
                indice = indice + 1;
            }else{
                indice = current_difficulty;
            }
        }
        qDebug() << resultados << "\n";
        qDebug() << "DETECTED DIFFICULTY:" << detected_difficulty;


        if(detected_difficulty == current_difficulty)
        {
            seguir = 0;
            qDebug() << "DETECTED A FOLDER";
            emit resultado_sobre_carpeta_primeo_nuevo(string_to_hash_as_qstring, resultados);
        }
    }
}
