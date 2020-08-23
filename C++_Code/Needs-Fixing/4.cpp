/*
 * Lab 8 Pre-Lab Assignment
 * Author: Md Ali
 * C.S.1428.501
 * Lab Section: L01

*/
// Move the indicated code into functions.

#include <iostream>
using namespace std;

void WelcomeMessage();

double JediLevel();

int main()
{

    double jedi_level;

    WelcomeMessage();

    jedi_level = JediLevel();

    // this should remain inside your main function
    cout << "Your Jedi Level is : " << jedi_level;

    return 0;
    }

    void WelcomeMessage()
            {
                cout << "Welcome to my fabulous Jedi power level calculator!" << endl
                     << "This program will take your age, weight, and" << endl
                     << "midichlorean count and return your Jedi power level!"
                     << endl << endl;
            };

    double JediLevel()
    {
        double jedi_level;

        double age, weight, mcc;

        cout << "please enter your age : ";
        cin >> age;
        cout << "please enter your weight : ";
        cin >> weight;
        cout << "please enter your midicholrean count : ";
        cin >> mcc;
        jedi_level = (mcc * age) / (weight * weight);

        return jedi_level;
    };