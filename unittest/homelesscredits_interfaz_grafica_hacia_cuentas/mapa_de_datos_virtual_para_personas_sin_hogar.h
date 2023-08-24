#ifndef MAPA_DE_DATOS_VIRTUAL_PARA_PERSONAS_SIN_HOGAR_H
#define MAPA_DE_DATOS_VIRTUAL_PARA_PERSONAS_SIN_HOGAR_H

#include <QObject>
#include <QDebug>

class mapa_de_datos_virtual_para_personas_sin_hogar : public QObject
{
    Q_OBJECT
public:
    explicit mapa_de_datos_virtual_para_personas_sin_hogar(QObject *parent = nullptr);

    void initialize_hash_function();
    QString string_to_homelesscredits_hash(QString string_to_hash, qint32 iterations);
    QMap<QString, QVariant> apply_self_additive_rotation(QString string_to_hash);
    int get_character_index(QString character_to_rotate);
    int rotate_character(QString character_to_rotate, qint32 iterations);
    QString reduce_string(QString additive_string, int target_size, qint32 iterations);


    void unit_test_rotate_character();

private:
    QString character_map;

signals:

};

#endif // MAPA_DE_DATOS_VIRTUAL_PARA_PERSONAS_SIN_HOGAR_H
