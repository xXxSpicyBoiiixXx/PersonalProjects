//
// Created by Md Ali on 7/14/18.
// Menu.cpp

#include <iostream>
#include "InfoDataTypes.h"

using namespace std;

// Gives 13 options for user to input from
void MenuOptionDataTypes()
{
    cout << "Please select a data type you wish to know the address and size (in bytes): " << endl
         << "1. int" << endl << "2. bool" << endl << "3. char" << endl << "4. short" << endl
         << "5. long int" << endl << "6. long float"  << endl << "7. double" << endl
         << "8. long double" << endl << "9. double array[5]" << endl
         << "10. int array [4]" << endl << "11. pointer variable pointing to integer" << endl
         << "12. pointer variable pointing to integer" << endl << "13. End Program" << endl;
}

// Receives input from user, if input is incorrect will return error message
int MenuChoice()
{
    bool validMenu;

    int MenuInput;

    while (!validMenu)
    {
        validMenu = true; //Assume the cin will be an integer.
        cout << endl << "Please enter one of the options above: ";
        cin >> MenuInput;

        //cin.fail() checks to see if the value in the cin
        //stream is the correct type, if not it returns true,
        //false otherwise.
        if (cin.fail() or MenuInput < 1 or MenuInput > 13)

        {
            cin.clear(); //This corrects the stream.
            cin.ignore(); //This skips the left over stream data.

            cout << endl
                 << "Please enter a number between 1-13 from the menu"
                 << endl << endl;

            MenuOptionDataTypes();

            validMenu = false; //The cin was not an integer between 1-13 so try again.
        }

    }

    return MenuInput;
}
