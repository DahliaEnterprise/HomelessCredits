#include "homelesscredits_hash_function.h"

homelesscredits_hash_function::homelesscredits_hash_function(QObject *parent)
    : QObject{parent}
{

}

void homelesscredits_hash_function::initialize_hash_function(QString set_character_map)
{
    character_map = QString("%1").arg(set_character_map);
}
void homelesscredits_hash_function::string_to_homelesscredits_hash(QString string_to_hash, qint32 iterations)
{
    QMap<QString, QVariant> result_of_string_with_additive_rotation = this->apply_self_additive_rotation(string_to_hash);
    QString additive_string = result_of_string_with_additive_rotation.value("result").toString();
    QString additive_string_reduced = this->reduce_string(additive_string, 16, iterations);
    qDebug() << additive_string_reduced.toUtf8().toHex();
}

QMap<QString, QVariant> homelesscredits_hash_function::apply_self_additive_rotation(QString string_to_hash)
{
    QMap<QString, QVariant> output = QMap<QString, QVariant>();

    //Rename
    QString source_string = QString("%1").arg(string_to_hash);

    //Generated result string
    QString result_string = QString();

    //For every character consecutively rotate using also every character
    int total_characters_appended_to_result = 0;
    qint32 total_times_to_rotate = 0;
    while(total_characters_appended_to_result < source_string.length())
    {
        //Initialize character to rotate variable
        QString character_to_rotate = QString("%1").arg(source_string.at(total_characters_appended_to_result));

        qDebug() << total_characters_appended_to_result;
        //Rotate character by every character(index) times the total characters produced(plus 2) times the source string index(plus 2)
        int additive_source_index = 0;
        while(additive_source_index < source_string.length())
        {
            int character_index_to_rotate = this->get_character_index(source_string.mid(additive_source_index, 1));
            total_times_to_rotate = total_times_to_rotate + character_index_to_rotate + 2;
            int index_of_rotated_character = rotate_character(source_string.mid(additive_source_index, 1), total_times_to_rotate);
            character_to_rotate.clear();
            character_to_rotate = QString("%1").arg(character_map.mid(index_of_rotated_character, 1));


            additive_source_index = additive_source_index + 1;
        }


        result_string = result_string.append(character_to_rotate);

        //next character to rotate amongst all the characters index position
        total_characters_appended_to_result = total_characters_appended_to_result + 1;
    }

    output.insert("result", QVariant(result_string));

    return output;

}

int homelesscredits_hash_function::get_character_index(QString character_to_rotate)
{
    int output = -1;

    int index_iterator = 0;
    int index_found = -1;
    while(index_iterator < character_map.length())
    {
        if(character_to_rotate.compare(character_map.mid(index_iterator, 1)) == 0)
        {
            index_found = index_iterator;
            index_iterator = character_map.length();
        }else{

            index_iterator = index_iterator + 1;
        }
    }

    output = index_found;

    return output;
}

int homelesscredits_hash_function::rotate_character(QString character_to_rotate, qint32 iterations)
{
    int output = -1;

    //Get the current index
    int current_character_index = this->get_character_index(character_to_rotate);

    //Fault check
    if(current_character_index == -1)
    {
        qDebug() << "NON ACCEPTED CHARACTER";
    }else if(current_character_index > -1)
    {
        int rotated_index = current_character_index;
        qint32 iterations_consumed = 0;
        int keep_consuming_iterations = 1;
        while(keep_consuming_iterations == 1)
        {
            rotated_index = rotated_index + 1;
            if(rotated_index == character_map.length())
            {
                rotated_index = 0;
            }

            iterations_consumed = iterations_consumed + 1;

            if(iterations_consumed == iterations)
            {
                output = rotated_index;
                keep_consuming_iterations = 0;
            }
        }
    }

    return output;
}

QString homelesscredits_hash_function::reduce_string(QString additive_string, int target_size, qint32 iterations)
{
    QString output = QString();

    //This function assumes that string_to_scale.length is greater than target_size.
    //This function must reduce the string in a predictable manner. (no random)
    QString reduced_string = QString();
    int additive_string_index = 0;
    int total_characters_produced = 0;
    while(total_characters_produced < target_size)
    {
        qint32 total_iterations_consumed = 0;
        while(total_iterations_consumed < ((total_iterations_consumed + 2) * iterations))
        {
            additive_string_index = additive_string_index + 1;
            if(additive_string_index == additive_string.length())
            {
                additive_string_index = 0;
            }
            total_iterations_consumed = total_iterations_consumed + 1;
            //qDebug() << additive_string_index << " | " << total_iterations_consumed;
        }

        reduced_string.append(additive_string.mid(additive_string_index, 1));
        additive_string = additive_string.remove(additive_string_index, 1);
        //qDebug() << reduced_string << " | " << additive_string << " | " << additive_string_index;
        total_characters_produced = total_characters_produced + 1;
    }
    output = reduced_string;
    qDebug() << output;
    return output;
}

void homelesscredits_hash_function::unit_test_rotate_character()
{
    /*
    int character_map_index_of_rotated_character = this->rotate_character(QString("a"), (25 * 100000));
    qDebug() << character_map.mid(character_map_index_of_rotated_character, 1);
    */
    qDebug() << this->reduce_string(QString("abc"), 1, 3);
}
