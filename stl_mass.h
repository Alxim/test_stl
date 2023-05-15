#ifndef STLMASS_H
#define STLMASS_H

using namespace std;

#include <iostream>
#include <map>
#include <regex>
#include <mutex>

typedef std::map<string, int> MyMap;
typedef pair<string, int> MyPair;

class StlMass
{
public:
    StlMass();

    /*!
     * \brief setValue - установить значение по идентификатору
     * \param id - идентификатор
     * \param value - значение
     * \return - если удаплось установить, то возвращается правада, иначе ложь
     */
    bool setValue(string id, int value);


    /*!
     * \brief increment - увеличить значение по идентификатору на единицу
     * \param id - идентификатор
     * \return - возвращает положительное новое значение в случае успеха или -1 в случае провала
     */
    int increment(string id);

    mutex my_mutex;

private:

    const regex reg = regex(R"([ABCEHIKLNOPRSTUEXYZ][1-9](-[ABCEHIKLNOPRSTUEXYZ][1-9]){0,9})");

    /*!
     * \brief mass - массив идентификаторов
     */
    MyMap mass;
};

#endif // STLMASS_H
