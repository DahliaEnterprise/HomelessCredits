#include "homelesscredits_hash_function.h"
#include <QCoreApplication>
#include <QDateTime>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString character_table = QString("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+{}[]~`;:'\"<>,. ?");
    QString unittest_character_table = QString("abcd");

    QString string_to_hash = QString("sometimeswhenthecosasbegettinallwilditwillsettle");
    QDateTime time1 = QDateTime::currentDateTime();
    string_to_hash.append(QString::number(time1.toSecsSinceEpoch(), 10));
    QString unittest_string_to_hash = QString("aaaa");

    //Define input string (typically this is intended for the combined textual information such as: block number, list of transaction information, timestamp)
    homelesscredits_hash_function * hash = new homelesscredits_hash_function();
    hash->initialize_hash_function(character_table);
    //hash->unit_test_rotate_character();
    hash->string_to_homelesscredits_hash(string_to_hash, 100);



    return a.exec();
}
