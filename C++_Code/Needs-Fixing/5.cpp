/*
 * Lab 9 Pre-Lab Assignment
 * Author: Md Ali
 * C.S. 1428.501
 * Lab Section: L01
 */

// Add the following functions:

// 1. 'getRadius' asks the user to enter the radius of a circle
//     and returns the given value. (should return a double)

// 2. 'calcArea' takes the radius and returns the area of a circle.

// 3. 'printResults' void type function that should print the results to 
//    console. 

// Your function needs to have a local variable called 'PI' which holds the
// value '3.14159'.

// The function call is provided, you just need to implement the
// function prototype and function definition.

#include <iostream>
using namespace std;

double getRadius();
double calcArea(double radius);
void printResults(double area);

int main()
{
    double radius,
            area;

 radius = getRadius();
 area = calcArea(radius);
 printResults(area);

    return 0;
}

double getRadius()
{
    double radius;
    cout << "Enter that dank radius boi: ";
    cin >> radius;

    return radius;
}

double calcArea(double radius)
{
    const double PI = 3.14159;

    double area;

    area = PI * radius * radius;

    return area;
}

void printResults(double area)
{
    cout << "The area of your circle is " << area << " units squared."
         << endl;
}