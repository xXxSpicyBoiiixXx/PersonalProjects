/*
 * Author: Md Ali
 * Section: 1428.501
 * Lab Section: L01
 */

#include <iostream>
#include <ctime>   // for seeding rand
#include <cstdlib> // C standard library

using namespace std;

int main() {

    int random_number,
            n,              //n is counting the number of turns
            turn = 1,
            health1 = 100,
            health2 = 100;

    char next; // to keep the game going

    // seeds rand (needed for getting random numbers)
    srand(time(NULL));

    // randomly generates a number 1 - 20 inclusively
    cout << "Press any key to play the dice game" << endl;
    cin >> next;
    cout << "Both players have a life of 100 health, press any key to continue" << endl;
    cin >> next;
    cout << "Let's begin C++ style #SAWMOVIES, press any key to continue "
         << "or press 'q' or 'Q' to quit" << endl;
    cin >> next;
    while (health1 > 0 or health2 > 0)

    {
        if (n == 0 and health2 > 0) {
            while (next != 'q' or 'Q') {
                do {
                    if(health2 < 0)
                    {
                        break;
                    }
                    random_number = rand() % 20 + 1;

                    cout << "You rolled a " << random_number << ": ";

                    if (random_number == 20) {
                        cout << "CRITICAL HIT" << endl;
                        health2 -= 2*random_number;
                        n = 0;

                    } else if (random_number >= 12 and random_number <= 19) {
                        cout << "Attack Strikes" << endl;
                        health2 -= random_number;
                        n = 0;
                    } else {
                        cout << "Attack Misses" << endl;
                        n = 1;
                        break;
                    }


                } while (random_number > 11);

                cout << "Next player's turn sorry bruh" << endl;
                cout << "Player 2 health = " << health2 << endl;
                if(health2 <= 0)
                {
                    cout << "Player 2 aint balling pay up GAME OVER" << endl;
                    break;
                }
                cout << "Please press any key to continue or press 'Q' to quit." << endl;
                cin >> next;

                break;
            }

        }
        if (n == 1 and health1 > 0) {
            while (next != 'q' or 'Q' and health1 > 100 and health2 > 100)
            {
                do {
                    if(health1 < 0)
                    {
                        break;
                    }
                    random_number = rand() % 20 + 1;

                    cout << "You rolled a " << random_number << ": ";

                    if (random_number == 20) {
                        cout << "CRITICAL HIT" << endl;
                        health1 -= 2*random_number;
                        n = 1;

                    } else if (random_number >= 12 and random_number <= 19) {
                        cout << "Attack Strikes" << endl;
                        health1 -= random_number;
                        n = 1;
                    } else {
                        cout << "Attack Misses" << endl;
                        n = 0;
                        break;
                    }

                } while (random_number > 11);

                cout << "Next player's turn sorry bruh" << endl;
                cout << "Player 1 health = " << health1 << endl;
                if(health1 <= 0)
                {
                    cout << "Player 1 aint balling pay up GAME OVER" << endl;
                    break;
                }
                cout << "Please press any key to continue or press 'Q' to quit." << endl;
                cin >> next;
                break;
            }


        }

    }

    return 0;

}