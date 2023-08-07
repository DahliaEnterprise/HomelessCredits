#include "homelesscredits_hash_function.h"
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString character_table = QString("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+{}[]~`;:'\"<>,. ?");

    QString string_to_hash = QString("thequickbrownfoxjumpsoverthelazydogTHEQUICKBROWNFOXJUMPSOVERTHELAZYDOG");

    //Define input string (typically this is intended for the combined textual information such as: block number, list of transaction information, timestamp)
    homelesscredits_hash_function * hash = new homelesscredits_hash_function();
    hash->initialize_hash_function(character_table);
    hash->string_to_homelesscredits_hash(string_to_hash, 1000);



    return a.exec();
}
