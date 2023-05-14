#include "stl_mass.h"

//«D», «F», «G», «J», «M», «Q», «V» и цифра «0».

StlMass::StlMass()
{
    symbols.push_back('A');
    symbols.push_back('B');
    symbols.push_back('C');

    symbols_ban.push_back('D');

    symbols.push_back('E');

    symbols_ban.push_back('F');
    symbols_ban.push_back('G');

    symbols.push_back('H');
    symbols.push_back('I');

    symbols_ban.push_back('J');

    symbols.push_back('K');
    symbols.push_back('L');

    symbols_ban.push_back('M');

    symbols.push_back('N');
    symbols.push_back('O');
    symbols.push_back('P');

    symbols_ban.push_back('Q');

    symbols.push_back('R');
    symbols.push_back('S');
    symbols.push_back('T');
    symbols.push_back('U');

    symbols_ban.push_back('V');

    symbols.push_back('E');
    symbols.push_back('X');
    symbols.push_back('Y');
    symbols.push_back('Z');

    vector<char>::iterator iter_sym;

    for(iter_sym = symbols.begin() ; iter_sym != symbols.end() ; iter_sym++)
    {
        char curr_char = *iter_sym;

        for(int i = 1; i < 10; i++)
        {
            string str;
            str.push_back(curr_char);
            str.push_back(char(48+i) );

            cout << str << endl;
            mass.insert( MyPair(str, 0) );
        }
    }

//    cout << symbol;
}
