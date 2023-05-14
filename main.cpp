#include "stl_mass.h"


int main()
{
    StlMass test;

    MyMap gg;

    gg.insert( MyPair("ll", 55) );

    cout << gg.at("ll") << endl;
    cout << "Hello World!" << endl;
    return 0;
}
