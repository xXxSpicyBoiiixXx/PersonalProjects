//
// Created by Md Ali on 7/16/18.
//

#include <iostream>
#include "InfoDataTypes.h"
#include "Menu.h"

using namespace std;

char OutputInfo(int number)
{
    char Statement;

    switch (number) {
        case 1:
            IntInfo();
            break;

        case 2:
            BoolInfo();
            break;

        case 3:
            CharInfo();
            break;

        case 4:
            ShortInfo();
            break;

        case 5:
            LongIntInfo();
            break;

        case 6:
            LongFloatInfo();
            break;

        case 7:
            DoubleInfo();
            break;

        case 8:
            LongDoubleInfo();
            break;

        case 9:
            DoubleArrayInfo();
            break;

        case 10:
            IntArrayInfo();
            break;

        case 11:
            PointerPointIntInfo();
            break;

        case 12:
            PointerPointFloatInfo();
            break;

        case 13:
            return 1;
    }

    cout << "Press any key to find more information on another data type or press 'N' to end program" << endl;
    cin >> Statement;

    return Statement;
}

void ExitStatement()
{
    cout << "You have exited the program!" << endl
         << "- xXx_Spicy_Boiii_xXX (Md Ali)" << endl;
}