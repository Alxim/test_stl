#include "stl_mass.h"


StlMass::StlMass()
{
}


//************************************************************************************************************************

bool StlMass::setValue(string id, int value)
{
    if( regex_match(id.data(), reg) == 0 )
    {
        cout << "Id " << id << " not find" << endl;
        return false;
    }

    MyMap::iterator result = mass.find(id);

    if( result == mass.end() )
    {
        //  Идентификатор ещё не существует. Принимает значение по умолчанию = 0
        //  Увеличиваем на 1 и возвращаем результат
        mass.insert( MyPair(id, value) );
        cout << "Insert value " << value << endl;
        return true;
    }

    mass.erase(id);
    mass.insert( MyPair(id, value) );
    cout << "Update value " << value << endl;
    return true;
}


//************************************************************************************************************************

int StlMass::increment(string id)
{
    if( regex_match(id.data(), reg) == 0 )
    {
        cout << "Id " << id << " not find" << endl;
        return -1;
    }

    MyMap::iterator result = mass.find(id);

    if( result == mass.end() )
    {
        //  Идентификатор ещё не существует. Принимает значение по умолчанию = 0
        //  Увеличиваем на 1 и возвращаем результат

        cout << "Increment success. Current value " << id << " : " << 1 << endl;
        mass.insert( MyPair(id, 1) );
        return 1;
    }

    int value = mass.at(id);
    value++;

    mass.erase(id);
    mass.insert( MyPair(id, value) );
    cout << "Increment success. Current value " << id << " : " << value << endl;
    return value;
}
