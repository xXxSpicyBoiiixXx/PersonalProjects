/*
 * PreLab 4 Assignment
   Author: Md Ali
   Section: 1428.501
   Lab Section: L01
*/

// The following is an extremely scientific personality test that can predict
// how well you will do in this course.
// Fill in the area below with the requested code.

#include <iostream>

using namespace std;

int main()
{
     char answer;
     string message;

     cout << "Is Star Trek better than Star Wars? ('Y' or 'N')" << endl;
     cin >> answer;

     switch (answer)
     {
         case 'y' :
         case 'Y' :

          cout << "You think Star Trek is better than Star Wars..." << endl;
          message = "Wrong! You are likely to fail this class...";
          break;

         case 'n' :
         case 'N' :

          cout << "You do not think think Star Trek is better than Star Wars..." << endl;
          message = "Correct! You will undoubtedly ace this class!!!!" ;
          break;

         default:

          message = "Invalid Input. This does not bode well for you.";
     }

     cout << message << endl;

     return 0;
}
