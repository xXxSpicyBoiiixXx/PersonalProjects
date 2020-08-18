/*
# FILE: Jedi_midi-chlorian.cpp
# USAGE: User interaction
# DESCRIPTION: Simple C++ code to calculate midi-cholrian of a potential Jedi. 
# OPTIONS: -- 
# REQUIREMENTS: -- 
# BUGS: -- 
# AUTHOR: xXxSpicyBoiiixXx
# ORGANIZATION: -- 
# VERSION: 1.0
# CREATED: 08/18/2018
# REVISION: -- 
*/

#include <iostream>

using namespace std;

int main()
{
    // Creating integer variables for 'midi-chlorian count', 'age', and 'IQ'. Creating double variable for 'Jedi Level'.
    double Jedi_Level;

    int midi_chlorians,
        age,
        IQ;

    // Prompt and recieve from the user for midi-chlorian count, age, IQ
    cout << "What is your midi-chlorian count?" << endl;
    cin >> midi_chlorians;

    cout << "What is your age?" << endl;
    cin >> age;

    cout << "What is your IQ?" << endl;
    cin >> IQ;

    // Calculate and assign the user's Jedi level
    Jedi_Level = (midi_chlorians * age) / (90000.0 - (IQ *= IQ));

    // Displaying the user's Jedi Level to the console
    cout << "Your Jedi Level is: " << Jedi_Level << endl
         << "Press any key to exit the program." << endl;

    return 0;
}




