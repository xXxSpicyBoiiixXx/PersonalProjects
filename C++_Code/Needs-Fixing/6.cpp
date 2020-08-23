/*
 * Lab 10 Pre-Lab Assignment
 * Author: Md Ali
 * C.S.1428.501
 * Lab Section: L01
 */

// Write a function that multiplies each element in the array "myArray"
// by the variable "multiplyMe".

#include <iostream>

using namespace std;

void Multiplier(int multipler, int SIZE, int dank[SIZE]);


int main()
{
    const int SIZE = 10;
    int myArray [SIZE] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    int multiplyMe = 5;


    Multiplier(multiplyMe, SIZE, myArray);


    // print the array
    for(int i=0; i < SIZE; i++)
    {
        cout << myArray[i] << " ";
    }
    cout << endl;

    return 0;

}

void Multiplier(int multipler, int SIZE, int dank[SIZE])
{
    for(int i = 0; i < SIZE; i++)
    {
        dank[i] = multipler * dank[i];
    }
}