/*
 * PreLab 5 Assignment
 * Author: Md Ali
 * C.S. 1428.501
 * Lab Section: L01
 */

// Finish the following program which adds up all integers from 0 to
// the user's given number inclusively using a FOR loop. The total should be
// assigned to the variable 'total'.

#include <iostream>
using namespace std;


int main()
{
    int number;
    int total = 0;

    cout << "Enter a positive integer to find the summation of"
         << " all numbers from 0 to the given number." << endl;
    cin >> number;

        for (int i = 1; i <= number;)
        {
            total = total + i;
            i = i + 1;
        }
        cout << "Total : " << total << endl;

    return 0;
}
