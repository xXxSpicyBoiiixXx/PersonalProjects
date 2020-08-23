/*
# FILE: Jedi_midi-chlorian.cpp
# USAGE: User interaction
# DESCRIPTION: Simple C++ code 
# OPTIONS: --
# REQUIREMENTS: --
# BUGS: --
# AUTHOR: xXxSpicyBoiiixXx
# ORGANIZATION: --
# VERSION: 1.0
# CREATED: 08/18/2018
# REVISION: --
*/

/*

 PreLab 2 Assignment
 Author: Md Ali
 Section: 1428.501
 Lab Section: L01


   Write a program that copies the data in the
   prelab input file to an output file "flux_capacitor"
   so that it is formatted the same in both files.

   Additionally add 30 to the year when you rewrite
   it to the output file to help Marty Mcfly get back to
   his proper time.
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // declaring variables
    string firstName;
    string lastName;
    int year;


    // declare input file stream variable and open file
    ifstream fin;
    fin.open("prelab_input.txt");

    // Test to see if file correctly opened. If statements will
    // be learned in the future. For now, don't worry about
    // understanding this.
    if (!fin)
    {
        cout << "ERROR - File failed to open. make sure that "
             << "the input file and this file are in the"
             << "same directory" << endl;
        return -1; // Return statement will terminate the program. We do not want
        // to continue if we do not have a valid input file.
    }

    // declare output file stream varaible and open file
    ofstream fout;
    fout.open("flux_capacitor.txt");

    // Reading from input data
    fin >> firstName >> lastName >> year;

    // Adding 30 years to get back to real time
    year+=30;

    //Exporting data
    fout << firstName << " " << lastName << " " << year;

    //Let dat boiii know whats up
    cout << "30 years have been added to the flux capacitor."
         << endl;

    // closing files
    fin.close();
    fout.close();

    return 0;
}
