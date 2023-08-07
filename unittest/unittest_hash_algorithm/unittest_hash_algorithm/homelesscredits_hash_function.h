#ifndef HOMELESSCREDITS_HASH_FUNCTION_H
#define HOMELESSCREDITS_HASH_FUNCTION_H

#include <QObject>
#include <QDebug>

class homelesscredits_hash_function : public QObject
{
    Q_OBJECT
public:
    explicit homelesscredits_hash_function(QObject *parent = nullptr);

    void initialize_hash_function(QString set_character_map);
    void string_to_homelesscredits_hash(QString string_to_hash, qint32 iterations);
    void apply_self_additive_rotation(QString string_to_hash, qint32 iterations);
    int get_character_index(QString character_to_rotate);
    int rotate_character(QString character_to_rotate, qint32 iterations);
    void unit_test_rotate_character();

private:
    QString character_map;

signals:

};

#endif // HOMELESSCREDITS_HASH_FUNCTION_H
