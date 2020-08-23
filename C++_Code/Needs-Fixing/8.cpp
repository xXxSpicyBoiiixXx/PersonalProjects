/*
   File: prog2_mha27_str28.cpp

   Author: Md Ali, Steven Rodda
   C.S.1428.501
   Lab Section: L01, L01
   Program: #2
   Due Date: 06/14/18

   This program reads the length of one side of a cube (in inches) and
   the dimensions of a rectangular prism (in inches) from an input file,
   prog2_501inp.txt. The program then calculates the surface area of the
   cube and the surface area of the rectangular prism. The dimensions
   of the cube and the dimensions of the rectangular prism along with
   the calculated surface areas are then written to an output file,
   prog2_501out.txt, with content and layout shown below. Numeric output
   is formatted to two decimal places. After output is generated and written
   to the output file, an appropriate sentence is written to the screen
   letting the user know the name of the data file to which the surface
   area report has been written.

   An appropriate message is displayed to the screen if there is a problem
   opening either the input file or the output file.

   Input (file - prog2_501inp.txt):  side, length, width, height (doubles)
   Constants: none
   Output (Sample Console Screen):

           Author's Name
           C.S.1428.?          // '?' represents author's lecture section #
           Lab Section: L?     // '?' represents student's lab section #
           --/--/--            // dashes represent due date, month/day/year
              <blank line>
              <blank line>
           <Appropriate message indicating the name of the output file.>

   Output (file - prog2_501out.txt):

           Author's Name
           C.S.1428.?          // '?' represents author's lecture section #
           Lab Section: L?     // '?' represents student's lab section #
           --/--/--            // dashes represent due date, month/day/year
              <blank line>
              <blank line>
           The surface area of a cube with sides of length ? is ? .
           The surface area of a ? by ? by ? rectangular prism is ? .

    =================================================================

   <Output will vary based on input values.>

*/

#include <iostream>  // For console display
#include <fstream>   // For inputting and outputting files.
#include <cstdlib>   // For pause command
#include <iomanip>   // To set decimal points out to 2

using namespace std;      // Using standard

int main( )
{

    // Created variables to be read into by an input file
    // and variables to store surface area value.
    double length_cube,
           length_rectangular_prism,
           width_rectangular_prism,
           height_rectangular_prism,
           surface_area_cube,
           surface_area_rectangular_prism;

    // Inputting file stream variable and opening file.
    ifstream fin;
    fin.open("prog2_501inp.txt");

    // If no such file exist, prompt the user that the file
    // does not exist and the program has been terminated.
    if (!fin)
    {
        cout << endl << endl
             << "***Program Terminated.***" << endl << endl
             << "Input file failed to open." << endl;

        system("PAUSE > NUL");

        return 1;
    }

    // Writes to an existing output file 'prog2_501out.txt'
    // or creates an output file in a text document format.
    ofstream fout;
    fout.open("prog2_501out.txt");

    // If for some reason the output file can not be found
    // or there is a problem creating one, the program will
    // be terminated with an error message. Also the input
    // file will close.
    if (!fout)
    {
        cout << endl << endl
             << "***Program Terminated.***" << endl << endl
             << "Output file failed to open." << endl;

        fin.close();

        system("PAUSE > NUL");

        return 2;
    }

    // Reading from file and storing them into correct variables.
    fin >> length_cube >> length_rectangular_prism
        >> width_rectangular_prism >> height_rectangular_prism;

    // Calculate surface areas of the cube and rectangular prism.
    surface_area_cube = 6 * (length_cube * length_cube);
    surface_area_rectangular_prism = 2 * ((width_rectangular_prism * length_rectangular_prism)
                                       + (height_rectangular_prism * length_rectangular_prism)
                                          + (height_rectangular_prism * width_rectangular_prism));

    // Writing to the output file.
    fout << fixed << setprecision(2)
         << "Authors: Md Ali, Steven Rodda" << endl
         << "C.S.1428.501" << endl
         << "Lab Section: L01, L01" << endl
         << "06/14/18" << endl << endl
         << "The surface area of a cube with sides length " << length_cube
         << " is " << surface_area_cube << "." << endl
         << "The surface area if a " << length_rectangular_prism
         << " by " << width_rectangular_prism << " by " << height_rectangular_prism
         << " rectangular prism is " << surface_area_rectangular_prism << "." << endl;

    // Console display.
    cout << "Authors: Md Ali, Steven Rodda" << endl
         << "C.S.1428.501" << endl
         << "Lab Section: L01, L01" << endl
         << "06/14/18" << endl << endl
         << "The surface area report has been written to prog2_501.txt." << endl;

    // Closing input and out files.
    fin.close();
    fout.close();

    // Executes pause command and dumps output to a nul file.
    system("PAUSE > NUL");

    return 0;
}