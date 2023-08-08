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
    this->apply_self_additive_rotation(string_to_hash, iterations);

}

void homelesscredits_hash_function::apply_self_additive_rotation(QString string_to_hash, qint32 iterations)
{
    //Rename
    QString source_string = QString("%1").arg(string_to_hash);

    //Generated result string
    QString result_string = QString();

    //For every character consecutively rotate using also every character
    int total_characters_appended_to_result = 0;
    while(total_characters_appended_to_result < source_string.length())
    {
        //Initialize character to rotate variable
        QString character_to_rotate = QString("%1").arg(source_string.at(total_characters_appended_to_result));

        //Rotate character by every character(index) times the total characters produced(plus 2) times the source string index(plus 2)
        int additive_source_index = 0;
        while(additive_source_index < source_string.length())
        {
            qint32 total_times_to_rotate = 0;
            int character_index_to_rotate = this->get_character_index(source_string.mid(additive_source_index, 1));
            total_times_to_rotate = character_index_to_rotate + 2;
            total_times_to_rotate = total_times_to_rotate * (total_characters_appended_to_result + 2);
            total_times_to_rotate = total_times_to_rotate * (additive_source_index + 2);
            total_times_to_rotate = total_times_to_rotate * iterations;

            int index_of_rotated_character = rotate_character(source_string.mid(additive_source_index, 1), total_times_to_rotate);
            character_to_rotate.clear();
            character_to_rotate = QString("%1").arg(character_map.mid(index_of_rotated_character, 1));


            additive_source_index = additive_source_index + 1;
        }


        result_string = result_string.append(character_to_rotate);

        //next character to rotate amongst all the characters index position
        total_characters_appended_to_result = total_characters_appended_to_result + 1;
    }

    qDebug() << result_string;

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

void homelesscredits_hash_function::unit_test_rotate_character()
{
    //
    int character_map_index_of_rotated_character = this->rotate_character(QString("a"), (25 * 100000000));
    qDebug() << character_map.mid(character_map_index_of_rotated_character, 1);
}
