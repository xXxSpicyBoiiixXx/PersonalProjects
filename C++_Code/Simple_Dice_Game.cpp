/*
# FILE: Simple_Dice_Game.cpp
# USAGE: Just an execution is needed.
# DESCRIPTION: The following is a simple dice roller for a table top game. The code randomly generates a number. 
# OPTIONS: --
# REQUIREMENTS: -- 
# BUGS: -- 
# AUTHOR: xXxSpicyBoiiixXx
# ORGANIZATION: -- 
# VERSION: 1.0
# CREATED: 08/30/2018
# REVISION: --
*/

#include <iostream>
#include <ctime>   // for seeding rand
#include <cstdlib> // C standard library

using namespace std;

int main()
{

    int random_number;

    // seeds rand (needed for getting random numbers)
    srand(time(NULL));

    // randomly generates a number 1 - 20 inclusively
    random_number = rand() % 20 + 1;

    cout << "You rolled a " << random_number << ": ";


    if(random_number == 20)
    {
        cout << "CRITICAL HIT" << endl;
    }

    else if(random_number >= 12 and random_number <= 19)
    {
        cout << "Attack Strikes" << endl;
    }

    else
    {
        cout << "Attack Misses" << endl;
    }

    return 0;
}
