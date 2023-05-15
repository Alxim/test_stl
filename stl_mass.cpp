#include "stl_mass.h"


StlMass::StlMass()
{
}


//************************************************************************************************************************

bool StlMass::setValue(string id, int value)
{
    if( ! my_mutex.try_lock())
    {
        cout << "Unable set value to id(" << id << "/" << value << "). Mutex lock" << endl;
        return false;
    }

    if( regex_match(id.data(), reg) == 0 )
    {
        cout << "Id " << id << " not find" << endl;
        my_mutex.unlock();
        return false;
    }

    MyMap::iterator result = mass.find(id);

    if( result == mass.end() )
    {
        //  Идентификатор ещё не существует. Принимает значение по умолчанию = 0
        //  Увеличиваем на 1 и возвращаем результат
        mass.insert( MyPair(id, value) );
        cout << "Insert value " << value << endl;
        my_mutex.unlock();
        return true;
    }

    mass.erase(id);
    mass.insert( MyPair(id, value) );
    cout << "Update value " << value << endl;
    my_mutex.unlock();
    return true;
}


//************************************************************************************************************************

int StlMass::increment(string id)
{
    if( ! my_mutex.try_lock())
    {
        cout << "Unable increment to id = " << id << ". Mutex lock" << endl;
        return -1;
    }

    if( regex_match(id.data(), reg) == 0 )
    {
        cout << "Id " << id << " not find" << endl;
        my_mutex.unlock();
        return -1;
    }

    MyMap::iterator result = mass.find(id);

    if( result == mass.end() )
    {
        //  Идентификатор ещё не существует. Принимает значение по умолчанию = 0
        //  Увеличиваем на 1 и возвращаем результат

        cout << "Increment success. Current value " << id << " : " << 1 << endl;
        mass.insert( MyPair(id, 1) );
        my_mutex.unlock();
        return 1;
    }

    int value = mass.at(id);
    value++;

    mass.erase(id);
    mass.insert( MyPair(id, value) );
    cout << "Increment success. Current value " << id << " : " << value << endl;
    my_mutex.unlock();
    return value;
}
