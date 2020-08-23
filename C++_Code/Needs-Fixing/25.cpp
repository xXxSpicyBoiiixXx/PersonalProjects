/*
   File: prog1_mha27_str28.cpp

   Author: Md Ali, Steven Rodda
   C.S.1428.501
   Lab Section: L01, L01
   Program: #1
   Due Date: 06/11/18

   This program will prompt the user for the three radius values of an
   ellipsoid (in inches). Three different prompts are used in consideration
   of the user. The program allows for real input data. It calculates the
   volume of the ellipsoid. It then writes the identifying information of
   the author (or authors) and the three radius values of the ellipsoid
   along with the calculated volume to the console screen. The layout and
   content of the console screen are shown in the sample below.

   Input (keyboard): radius1, radius2, radius3  (doubles)
   Constants:        PI = 3.141592 (double)
   Output (screen):
             Author's Name
             C.S.1428.?          // '?' represents student's lecture section #
             Lab Section: L?     // '?' represents student's lab section #
             --/--/--            // dashes represent due date, month/day/year
                <blank line>
             The volume of an ellipsoid with radius values
             ?, ? and ? inches is ? cubic inches.

   =======================================================================

   <Output will vary based on actual input values.>

*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main( )
{
    const double PI = 3.141592;

    double radius1,
           radius2,
           radius3,
           volume_ellipsoid;

    cout << "Enter a value for the first radius (in inches): ";
    cin >> radius1;

    cout << "Enter a value for the second radius (in inches): ";
    cin >> radius2;

    cout << "Enter a value for the third radius (in inches): ";
    cin >> radius3;

    volume_ellipsoid = (4.0/3.0) * PI * radius1 * radius2 * radius3;

    cout << endl << endl
         << "Author's Name: Md Ali, Steven Rodda" << endl
         << "C.S.1428.501" << endl
         << "Lab Section: L01" << endl
         << "06/11/18" << endl << endl
         << "The volume of an ellipsoid with radius values "
         << radius1 << ", " << radius2 << " and " << radius3
         << " inches is " << volume_ellipsoid
         << " cubic inches." << endl;


    system("PAUSE>NUL");

    return 0;
}
