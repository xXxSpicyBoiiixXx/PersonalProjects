/*
   File: prog6_mha27_str28.cpp

   Author: Md Ali, Steven Rodda
   C.S.1428.501
   Lab Section: L01, L01
   Program: #6
   Due Date: 07/02/18

   This program reads integer data from an input file filling a
   2-dimensional array (4 rows, 5 columns). It then reports statistics
   about the data in the array.

   Functions are used to read, process and report the data to an output
   file. Each function is individually and appropriately documented. After
   all data are processed, a function is called to write an appropriate
   sentence to the screen letting the user know the name of the data file
   to which the array statistics have been written.

   Note: An appropriate message is displayed to the screen if either the
   input file or the output file fails to open.

   Processing:

   * A void function printIdInfo is called to print the authors' personal
     information (names, class/section number, lab section number, due date)
     on the first, second, third and fourth lines of output. printIdInfo prints
     two blank lines after the due date. The output is directed to a file or
     to the screen depending on the call.
        e.g  Authors' Names
             C.S.1428.?         // '?' represents three digit lecture section #
             Lab Section: L?    // '?' represents two digit lab section #
             --/--/--           // dashes represent due date, month/day/year
     		 	   <blank line>
     		 	   <blank line>
   * A void function fillArray is called to fill the array with integer
     data from an input file.
   * A typed function getTotal is called. It accepts a 2-D array as its
     argument and returns the integer total of all values stored in the
     array.
   * A typed function getAverage is called. It accepts the integer total
     of all elements (from getTotal) and returns the real average of all
     the elements stored in the array.
   * A typed function getRowTotal is called. It accepts a 2-D array as its
     first argument and an integer as its second argument (a specific row
     in the array) and returns the total of the values in the row specified.
     The user provides the actual row number for which the total is desired.
     The function, getRowTotal, adjusts that number to allow for array
     indices being offset by one in C++.
        e.g. If the user wants the total of the first row (which
             corresponds to array index 0), they provide a 1 as the
             second argument when they call the function getRowTotal.
   * A typed function getColumnTotal is called. It accepts a 2-D array as
     its first argument and an integer as its second argument (the specific
     column in the array) and returns the total of the values in the column
     specified. The user provides the actual column number for which the
     total is desired. The function, getColumnTotal, adjusts that number
     to allow for array indices being offset by one in C++.
        e.g. If the user wants the total of the first column (which
             corresponds to array index 0), they provide a 1 as the
             second argument when they call the function getColumnTotal.
   * A typed function getHighestInRow is called. It accepts a 2-D array as
     its first argument and an integer as its second argument (a specific
     row in the array) and returns the highest value in the row specified.
     The user provides the actual row number in which the highest value is
     to be located. The function, getHighestInRow, adjusts that number
     to allow for array indices being offset by one in C++.
        e.g. If the user wants the highest value in the first row (which
             corresponds to array index 0), they provide a 1 as the second
             argument when they call the function getHighestInRow.
   * A typed function getLowestInRow is called. It accepts a 2-D array as
     its first argument and an integer as its second argument (a specific
     row in the array) and returns the lowest value in the row specified.
     The user provides the actual row number in which the lowest value is
     to be located. The function, getLowestInRow, adjusts that number to
     allow for array indices being offset by one in C++.
        e.g. If the user wants the lowest value in the first row (which
             corresponds to array index 0), they provide a 1 as the
             second argument when they call the function getLowestInRow.
   * A void function printResults is called to print to an output file the
     total of all array elements; the average of all array elements; the
     row of which the calling routine requested the total and the total of
     the elements in that row; the column of which the calling routine
     requested the total and the total of the elements in that column; the
     row of which the calling routine requested the highest value and the
     highest value in that row; and the row of which the calling routine
     requested the lowest value and the lowest value in that row. Results
     are written in sentence form.
   * printIdInfo is called a second time with output directed to the screen.
   * A void function printFileNotification is called to print a statement
     to the screen letting the user know the name of the data file to which
     the array statistics have been written. The output file name is provided
     by the calling routine.(Refer to sample output below.)

   The following named constants are declared globally: ROWS & COLS - the
   number of rows & columns in the 2-D array being processed

   Locally declared named constants include:
      - a string to hold the authors' names
      - a string to hold the project's due date
      - an integer to hold the section number
      - an integer representing the maximum string length allowed for
        input and output file names which are stored in character arrays
        of that length

==========================================================================

   Input (file - prog6_?inp.txt): 4 rows, 5 columns (integers)

==========================================================================

   Layout and content of the output are shown in the samples below.

   Output (screen):
           Authors' Names
           C.S.1428.?         // '?' represents current lecture section #
           Lab Section: L?    // '?' represents two digit lab section #
           --/--/--           // dashes represent due date, month/day/year
             <blank line>
             <blank line>
           <Appropriate message indicating the name of the output file.>

   Output (file - prog6_?out.txt):

           Authors' Names
           C.S.1428.?         // '?' represents current lecture section #
           Lab Section: L?    // '?' represents two digit lab section #
           --/--/--           // dashes represent due date, month/day/year
             <blank line>
             <blank line>
           Sentence stating the total of all elements in the array.
           Sentence stating the average of all elements in the array.
           Sentence stating the total of the elements in row specified.
           Sentence stating the total of the elements in column specified.
           Sentence stating the highest value in row specified.
           Sentence stating the lowest value in row specified.

   =======================================================================

   <Output will vary based on input values.>

   =======================================================================
*/

// REPLACE THIS COMMENT WITH MAIN PROGRAM DOCUMENTATION.

#include <iostream>
#include <fstream>
#include <cstdlib>    // 4 Code::Blocks

using namespace std;

const int ROWS = 4,
        COLS = 5;

// REPLACE THIS COMMENT WITH PROTOTYPES
void printIdInfo( ostream & out, const string AUTHORS, const int SECTION, const string LAB_SECTION, const string DUE_DATE );
void fillArray ( ifstream & fin, int array_2d[][COLS]);
int getTotal(int array_2d[][COLS]);
double getAverage( int total_elements );
int getRowTotal ( int array_2d[][COLS], int row );
int getColumnTotal( int array_2d[][COLS], int column );
int getHighestInRow ( int array_2d[][COLS], int row );
int getLowestInRow ( int array_2d[][COLS], int row);
void printResults( ofstream & fout, int total_elements, double average,
                   int row_one, int row_total, int column_three, int column_total,
                   int row_two, int row_high, int row_four, int row_low);
void printFileNotification ( char output_filename[] );


int main ( )
{
    const string AUTHORS = "Md Ali, Steven Rodda",
            LAB_SECTION = "L01, L01",
            DUE_DATE = "07/02/18";

    const int SECTION = 501;

    const int MAX_LENGTH_FN = 20;

    char input_filename[MAX_LENGTH_FN + 1] = "prog6_501inp.txt",
            output_filename[MAX_LENGTH_FN + 1] = "prog6_501out.txt";

    int array_2d[ROWS][COLS];

    int total_elements,
            column_total,
            row_total,
            row_high,
            row_low;

    double average;

    ifstream fin;
    fin.open( input_filename );

    if ( !fin )
    {
        cout << endl << endl
             << "***Program Terminated.***" << endl << endl
             << "Input file failed to open." << endl;

        return 1;
    }

    ofstream fout;
    fout.open( output_filename );

    if ( !fout )
    {
        cout << endl << endl
             << " ***Program Terminated.*** " << endl << endl
             << "Output file failed to open." << endl;

        fin.close();

        return 2;
    }

    printIdInfo( fout, AUTHORS, SECTION, LAB_SECTION, DUE_DATE );
    fillArray ( fin, array_2d );
    total_elements = getTotal( array_2d );
    average = getAverage ( total_elements );
    row_total = getRowTotal ( array_2d, 1 );           // 1st row
    column_total = getColumnTotal ( array_2d, 3 );     // 3rd column
    row_high = getHighestInRow ( array_2d, 2 );        // 2nd row
    row_low = getLowestInRow ( array_2d, 4 );          // 4th row
    printResults( fout, total_elements, average,
                  1, row_total, 3, column_total, 2, row_high, 4, row_low );
    printIdInfo( cout, AUTHORS, SECTION, LAB_SECTION, DUE_DATE );
    printFileNotification ( output_filename );

    fin.close();
    fout.close();

    system("PAUSE>NUL");

    return 0;
}

/*
    Function: printIdInfo

    The void function, printIdInfo, prints the author's personal information
    (name, class/section number, lab section number and due date) on the first,
    second, third and fourth lines of output. printIdInfo then prints two blank
    lines after the due date. Output is directed to a file or to the screen
    depending on the call.

    e.g.
       Author(s)
       C.S.1428.?        // '?' replaced with three digit lecture section number
       Lab Section: L?   // '? replaced with two digit lab section numbers
       --/--/--          // due date in this format
           <blank line>
           <blank line>

    Receives:  output stream variable
    Constants: AUTHORS, SECTION, LAB_SECTION, DUE_DATE
    Returns:   nothing - prints author's personal information
*/

void printIdInfo( ostream & out, const string AUTHORS, const int SECTION, const string LAB_SECTION, const string DUE_DATE )
{
    out << "Author(s):" << AUTHORS << endl << "C.S.1428." << SECTION << endl
        << "Lab Section: " << LAB_SECTION << endl << DUE_DATE << endl << endl << endl;
}

/*
    Function: fillArray

    The void function, fillArray, reads from a file a set of integers set
    in rows and columns. The integers will be placed into a two dimensional
    array with respect to the file.

    Receives:  input file variable, two dimensional array (integer); in this order
    Constants: none
    Returns:   nothing - fills empty two dimensional array with integers
*/
void fillArray ( ifstream & fin, int array_2d[][COLS])
{

    for(int row_num = 0; row_num < ROWS; row_num++)
        for(int column_num = 0; column_num < COLS; column_num++)
            fin >>  array_2d[row_num][column_num];
}

/*
    Function: getTotal

    The typed function, getTotal, calculates the summation of all integers
    within the array.

    Receives:  Two dimensional array (integer)
    Constants: none
    Returns:   total (integer)
*/
int getTotal(int array_2d[][COLS])
{
    int total = 0;
    for(int i = 0; i < ROWS; i++)
        for(int n = 0; n < COLS; n++)
            total += array_2d[i][n];

    return total;

}

/*
    Function: getAverage

    The typed function, getAverage, calculates the average amongst all the integers
    inside of an array.

    Receives:  total_elements (integers)
    Constants: none
    Returns:   (double)
*/
double getAverage( int total_elements )
{
    return static_cast<double>(total_elements)/(ROWS * COLS);
}

/*
    Function: getRowTotal

    The typed function, getRowTotal, calculates the summation of
    all integers of a row in an array designated by the user.

    Receives:  Two dimensional array (integer), row (integer); in this order
    Constants: none
    Returns:   row_total (integer)
*/
int getRowTotal ( int array_2d[][COLS], int row ) //1st row
 {
     int row_total = 0;
     for(int i = 0; i < COLS; i++)
         row_total += array_2d[row-1][i];
     return row_total;
 }
/*
   Function: getColumnTotal

   The typed function, getColumnTotal, calculates the summation of
    all integers of a column in an array designated by the user.

   Receives:  Two dimensional array (integer), column (integer); in this order
   Constants: none
   Returns:   column_total (integer)
*/
 int getColumnTotal( int array_2d[][COLS], int column ) // 3rd column
 {
     int column_total = 0;
     for(int n = 0; n < ROWS; n++)
         column_total+=array_2d[n][column-1];
     return column_total;
 }

/*
    Function: getHighestInRow

    The typed function, getHighestInRow, returns the highest value in the


    Receives:  output stream variable
    Constants: AUTHORS, SECTION, LAB_SECTION, DUE_DATE
    Returns:   nothing - prints author's personal information
*/
 int getHighestInRow ( int array_2d[][COLS], int row ) // 2nd row
 {
     int highest_row = -999999999;
     for( int i = 0; i < COLS; i++)
         if(array_2d[row-1][i] > highest_row)
             highest_row = array_2d[row-1][i];

         return highest_row;
 }
 int getLowestInRow ( int array_2d[][COLS], int row) // 4th row
 {
 int lowest_row = 999999999;
 for(int n = 0; n < COLS; n++)
    if(array_2d[row-1][n] < lowest_row)
        lowest_row = array_2d[row-1][n];

return lowest_row;
 }

void printResults( ofstream & fout, int total_elements, double average,
               int row_one, int row_total, int column_three, int column_total,
                int row_two, int row_high, int row_four, int row_low)
{
    fout << "The sum total of all the data elements is " << total_elements << "."
            << endl <<"The average of all the data elements is " << average  << "." << endl
            << "The total of the data elements in row " << row_one << " is " << row_total << "."
            << endl << "The total of the data elements in column " << column_three << " is "
            << column_total << "." << endl << "The highest value in row " << row_two << " is "
    << row_high << "." << endl << "The lowest value in row " << row_four << " is " << row_low << "." << endl;

}

void printFileNotification ( char output_filename[] )
         {
             cout << "The processed array data has been written to " << output_filename
                  << "." << endl;
         }
