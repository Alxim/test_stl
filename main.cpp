#include "stl_mass.h"

int main()
{
    StlMass test;

    test.setValue("A1", 55);

    cout << test.increment("A1") << endl;
    cout << test.increment("A1") << endl;
    cout << test.increment("8A2") << endl;

    cout << "End work!" << endl;
    return 0;
}
