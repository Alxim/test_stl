#include "stl_mass.h"

//«D», «F», «G», «J», «M», «Q», «V» и цифра «0».

// [ABCEHIKLNOPRSTUEXYZ][1-9](-[ABCEHIKLNOPRSTUEXYZ][1-9]){0,9}

StlMass::StlMass()
{
}

void StlMass::setValue(string id, int value)
{
    if( regex_match(id.data(), reg) == 0 )
    {
        cout << "Id " << id << " not find" << endl;
        return;
    }

    MyMap::iterator result = mass.find(id);

    if( result == mass.end() )
    {
        //  Идентификатор ещё не существует. Принимает значение по умолчанию = 0
        //  Увеличиваем на 1 и возвращаем результат
        mass.insert( MyPair(id, value) );
    }

    mass.insert( MyPair(id, value) );
}

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
        mass.insert( MyPair(id, 1) );
        return 1;
    }

    int value = mass.at(id);
    value++;

    mass.erase(id);
    mass.insert( MyPair(id, value) );
    return value;
}
