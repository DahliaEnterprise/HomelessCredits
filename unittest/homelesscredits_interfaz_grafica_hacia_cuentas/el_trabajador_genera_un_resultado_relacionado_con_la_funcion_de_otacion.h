#ifndef EL_TRABAJADOR_GENERA_UN_RESULTADO_RELACIONADO_CON_LA_FUNCION_DE_OTACION_H
#define EL_TRABAJADOR_GENERA_UN_RESULTADO_RELACIONADO_CON_LA_FUNCION_DE_OTACION_H

#include "mapa_de_datos_virtual_para_personas_sin_hogar.h"

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QDateTime>
#include <QtMath>
#include <QRandomGenerator64>

class el_trabajador_genera_un_resultado_relacionado_con_la_funcion_de_otacion : public QObject
{
    Q_OBJECT
public:
    explicit el_trabajador_genera_un_resultado_relacionado_con_la_funcion_de_otacion(QObject *parent = nullptr);
    void inicilizar();


private:
    mapa_de_datos_virtual_para_personas_sin_hogar * identificador_de_mapa;

public slots:
    void generar_la_primera_carpeta();

signals:
    void resultado_sobre_carpeta_primeo_nuevo(QJsonObject);
};

#endif // EL_TRABAJADOR_GENERA_UN_RESULTADO_RELACIONADO_CON_LA_FUNCION_DE_OTACION_H
