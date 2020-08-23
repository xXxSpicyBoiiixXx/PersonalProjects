/*
   File: prog0_mha27.cpp

   Author: Md Ali
   C.S.1428.501
   Lab Section: L01
   Program: #0
   Due Date: 06/06/18

   This program
       - prints the student's name on the 1st line of output, last name first.
         e.g. Smith, John
       - prints 'C.S.1428.?' (without quotation marks) on the 2nd line of output
         with the student's lecture section number in place of the ? mark
       - prints 'Lab Section: ?' (without quotation marks) on the 3rd line of
         output with the student's lab section number in place of the ? mark
       - prints this program's due date on the 4th line of output
       - leaves line five blank
       - prints 'Major: ?' (without quotation marks) on the sixth line of
         output. The question mark is replaced with the author's major
       - prints 'Minor: ?' (without quotation marks) on the seventh line of
         output. The question mark is replaced with the author's minor or
         specialization or concentration, etc.
         Note: If the author does not have a minor or specialization or
         concentration, etc. something is 'made up' in order to complete
         the assignment.

   Input: none
   Constants: none
   Output (screen): Sample Output:

             Boop, Betty
             C.S.1428.?          // '?' represents student's lecture section #
             Lab Section: L?     // '?' represents student's lab section #
             --/--/--            // dashes represent due date, month/day/year
                <blank line>
             Major: Pig Latin
             Minor: Underwater Polo.

   Note: A student may have a specialization or concentration instead of a
         minor.
*/

#include <iostream>

using namespace std;

int main ()
{
   cout << "Ali, Md" << endl
        << "C.S.1428.501" << endl
        << "Lab Section: L01" << endl
        << "06/06/18" << endl << endl;

   cout << "Major: Physics and Applied Math" << endl
        << "Minor: Russian" << endl;

   return 0;
}
