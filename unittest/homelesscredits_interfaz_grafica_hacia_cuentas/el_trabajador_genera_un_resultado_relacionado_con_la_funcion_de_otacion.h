#ifndef EL_TRABAJADOR_GENERA_UN_RESULTADO_RELACIONADO_CON_LA_FUNCION_DE_OTACION_H
#define EL_TRABAJADOR_GENERA_UN_RESULTADO_RELACIONADO_CON_LA_FUNCION_DE_OTACION_H

#include <QObject>
#include <QJsonObject>
#include <QJsonValue>
#include <QDateTime>
#include <QtMath>

class el_trabajador_genera_un_resultado_relacionado_con_la_funcion_de_otacion : public QObject
{
    Q_OBJECT
public:
    explicit el_trabajador_genera_un_resultado_relacionado_con_la_funcion_de_otacion(QObject *parent = nullptr);

public slots:
    void generar_la_primera_carpeta();

signals:
    void resultado_sobre_carpeta_primeo_nuevo(QJsonObject);
};

#endif // EL_TRABAJADOR_GENERA_UN_RESULTADO_RELACIONADO_CON_LA_FUNCION_DE_OTACION_H
