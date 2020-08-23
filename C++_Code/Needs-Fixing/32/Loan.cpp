//
// Created by Spicy Boiii on 8/6/18.
//

#include <iostream>
#include <cmath>

using namespace std;

void Menu()
{
    cout << "Please select your loan type" << endl
         << "1. Car Loan" << endl
         << "2. Mortgage Lone" << endl
         << "3. End Program" << endl;
}

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
        if (cin.fail() or MenuInput < 1 or MenuInput > 3)

        {
            cin.clear(); //This corrects the stream.
            cin.ignore(); //This skips the left over stream data.

            cout << endl
                 << "Please enter a number between 1-3 from the menu"
                 << endl << endl;

            Menu();

            validMenu = false; //The cin was not an integer between 1-3 so try again.
        }

    }

    return MenuInput;
}

double calc_term(int year, double rate)
{
    double term;
    term = (year/rate) * 100;

    return term;
}

double calc_payment(int loan, double rate, double term)
{
    double payment;
    payment = (term + loan) * rate/100;

    return payment;
}