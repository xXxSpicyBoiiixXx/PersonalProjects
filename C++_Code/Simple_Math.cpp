/*
# FILE: Simple_Math.cpp
# USAGE: User interaction
# DESCRIPTION: Simple C++ code to introduce math operation in C++/
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
#include <iomanip>

using namespace std;

int main()
{
	// The Program should take two integers from the user and assign them to x and y
	// The program should then print the square of x and y + 10

	// Assigning 'x' and 'y' as integers.
	int x;
	int y;

	// The user will be entering the values for X and Y.
	cout << "Enter the value for X" << endl;
	cin >> x;

	cout << "Enter the value for Y" << endl;
	cin >> y;

	// x will be squared and y will have been added by 10.
	x*=x;
	y += 10;

	// This will output x squared and y added by 10.
	cout << "X squared = " << x << endl << "Y + 10  = " << y << endl;

	// Below will showcase the number of kilograms a user can lift.
	// This will convert pounds to kilograms. 

	// Assigning 'pds' and 'kg' as double
	double pds,kg;

	// Getting info from user.
	cout << "Many pounds can you lift?" << endl;

	cin >> pds;

	// Must add sassy remarks for humor sake
	cout << "Can you really lift " << pds << " pounds? #weak" << endl;

	//Converting pounds to kg
	kg = pds/2.20462;

	//Setting the decimal out to 5 points since
	//we are dividing by a number with 5 decimals
	cout << setprecision(5) << fixed;

	// Output towards user to show how many kg they can lift
	cout << "You can also lift " << kg << " kilograms :)" << endl;

	return 0;
}

