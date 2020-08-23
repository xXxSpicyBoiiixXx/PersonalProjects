/*
   File: prog5_mha27_str28.cpp

   Author: Md Ali, Steven Rodda
   C.S.1428.501
   Lab Section: L01
   Program: #5
   Due Date: --/--/--

   This programs reads an unknown number of records from an input file.
   Each record contains a salesperson's ID#(integer) and the amount of
   sales(real) for that salesperson. A negative ID# acts as a sentinel to
   signal the end of processing. Functions are used to read, process and
   report the data to an output file. Each function is individually and
   appropriately documented. After all records are processed, a function
   is called to write an appropriate sentence to the screen letting the
   user know the name of the data file to which the sales report has been
   written.

   Note: An appropriate message is displayed to the screen if either the
   input file or the output file fails to open.

   Processing:
   * A function is called to print personal identifying information to an
     output file.
   * A function is called to print to the output file a title and column
     headers for the sales report displayed in tabular form.
   * A function is called to read a salesman's record from an input file.
   * While the salesman's ID# is non-negative, process the current record:
	   * A function is called to calculate commission earned.
	   * A function is called to calculate the bonus earned.
       * A function is called to calculate the salesman's total earnings.
       * A function is called to print the salesman's information to the
         output file.
       * A function is called to read a salesman's record from the input
         file.
   * A function is called to print personal identifying information to the
     screen.
   * A function is called to print an appropriate sentence to the screen
     letting the user know the name of the data file to which the sales
     report has been written.

   Notes: Commission earned by each salesperson is based on a percentage
   of his/her sales that month. A bonus is paid those who exceed this
   month's sales target. The bonus is calculated at a percentage based on \
   the amount by which the target sales are exceeded.

   Functions Include:

   * A void function printIdInfo prints the author's personal information
     (name, class/section number, lab section number, due date) on the first,
     second, third and fourth lines of the output. printIdInfo prints two blank
     lines after the due date. The output is directed to a file or to the screen
     depending on the call.
        e.g.        Sally Iza Student
                    C.S.1428.?
                    Lab Section: L?
                    Due Date
                       <blank line>
                       <blank line>
   * A void function printColumnHeadings prints to the output file the
     title & column headings.
   * A void function readData uses only one read statement to "get" the
     values on each record from the input file - the employee ID# and
     monthly sales amount.
   * A typed function calcCommission calculates the amount of commission
     earned by each salesperson based on a commission rate of 10% of
     his/her sales that month. (10% is declared as a named constant in the
     calling routine.)
   * A typed function calcBonus calculates the bonus earned by a salesperson.
     A bonus is paid at a rate of 3% of sales to those who exceed this
     month's sales target of $30,000. The bonus calculation is based on
     the amount by which the target sales are exceeded. Note the example
     calculation below. (3% and $30000 are declared as named constants in
     the calling routine.)
   * A typed function calcEarnings calculates the total earnings for a
     salesperson.
   * A void function printReport prints to an output file the information
     for the current record as shown below.
   * A void function printFileNotification prints a statement to the screen
     letting the user know the name of the data file to which the sales
     report has been written.

   Input (file - prog5_501inp.txt): salesman's ID (integer)
                                    monthly sales figure (double)

   Constants: TARGET SALES AMOUNT = $30,000.00
              COMMISSION RATE = 10% (0.10)
              BONUS RATE = 3% (0.03)

   Output (screen):
          Author's Name
          C.S.1428.?       // '?' represents student's lecture section #
          Lab Section: L?  // '?' represents student's lab section #
          --/--/--         // dashes represent due date, month/day/year
             <blank line>
             <blank line>
          <Appropriate message indicating the name of the output file.>

   Output (file - prog5_501out.txt):

          Author's Name
          C.S.1428.?       // '?' represents student's lecture section #
          Lab Section: L?  // '?' represents student's lab section #
          --/--/--         // dashes represent due date, month/day/year
             <blank line>
             <blank line>
                              Monthly Sales Report
                                  <blank line>
          Sales ID#    Sales    Comments   Commission    Bonus    Earnings
          ----------------------------------------------------------------
           39808     35000.00   Met Goal     3500.00    150.00     3650.00
           45820     28000.00                2800.00      0.00     2800.00
            ...

   =======================================================================

   <Output will vary based on input values.>

*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void printIdInfo(ostream &out);
void printColumnHeadings(ofstream &fout);
void readData(ifstream &fin, int &employee_id, double &monthly_sales);
double calcCommission(double monthly_sales, const double COMMISSION_RATE);
double calcBonus(double monthly_sales, const double SALES_TARGET, const double BONUS_RATE);
double calcEarnings(double commission, double bonus);
void printReport(ofstream &fout, int employee_id, double monthly_sales, const double SALES_TARGET,
                 double commission, double bonus, double earnings);
void printFileNotification(ostream &cout);

int main()
{
    const double SALES_TARGET = 30000.00,
            COMMISSION_RATE = 0.10,
            BONUS_RATE = 0.03;

    double monthly_sales,
            commission,
            bonus,
            earnings;

    int employee_id = 1;  //Setting default number for while loop

    ifstream fin;
    fin.open("prog5_501inp.txt");

    if (!fin)
    {
        cout << endl << endl
             << "***Program Terminated.***" << endl << endl
             << "Input file failed to open!" << endl;

        return 1;
    }

    ofstream fout;
    fout.open("prog5_501out.txt");

    if(!fout)
    {
        cout << endl << endl
             << " ***Program Terminated.*** " << endl << endl
             << "Output file failed to open!" << endl;

        fin.close();

        return 2;
    }

    printIdInfo(fout);
    printColumnHeadings(fout);

    do
    {
        readData(fin, employee_id, monthly_sales);
        commission = calcCommission(monthly_sales, COMMISSION_RATE);
        bonus = calcBonus(monthly_sales, SALES_TARGET, BONUS_RATE);
        earnings = calcEarnings(commission, bonus);

        if(employee_id > 0)
        printReport(fout, employee_id, monthly_sales, SALES_TARGET, commission, bonus, earnings);
    }
    while(employee_id > 0);


    printIdInfo(cout);
    printFileNotification(cout);

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
    Constants: none
    Returns:   nothing - prints author's personal information
*/

void printIdInfo(ostream &out)
{
    out << "Md Ali, Steven Rodda" << endl << "C.S.1428.501" << endl
         << "Lab Section: L01, L01" << endl << "--/--/--" << endl
         << endl << endl;
}

/*
      Function: printColumnHeadings

      The void function, printColumnHeadings, prints to an output file a title
      and column headers for the sales report.

      e.g.
                            Monthly Sales Report

      Sales ID#      Sales    Comments   Commission     Bonus   Earnings
      ___________________________________________________________________

      Receives: output file variable
      Constants: none
      Returns: nothing - prints a title and column headers
*/

void printColumnHeadings(ofstream &fout)
{
    fout << "                    Monthly Sales Report" << endl << endl
         << "Sales ID#    Sales    Comments   Commission    Bonus    Earnings" << endl
         << "----------------------------------------------------------------" << endl;
}

/*
      Function:  readData

      The void function, readData, reads from an input file the employees'
      information: employee ID# and monthly sales amount.

      Receives: input file variable; employee_id (integer),
                monthly_sales (double); in this order
      Constants: none
      Returns: employee ID# & monthly sales amount read from an input file
*/

void readData(ifstream &fin, int &employee_id, double &monthly_sales)
{
    fin >> employee_id >> monthly_sales;
}

/*
      Function:  calcCommission

      The typed function, calcCommission, calculates the commission earned by 
      the employee being processed.

      Receives: monthly_sales (double); COMMISSION_RATE (const double);
                in this order
      Constants: COMMISSION_RATE
      Returns: commission (double)
*/

double calcCommission(double monthly_sales, const double COMMISSION_RATE)
{
    double commission;
    commission = monthly_sales * COMMISSION_RATE;

    return commission;
}

/*
      Function:  calcBonus

      The typed function, calcBonus, calculates the bonus earned. A bonus is 
      only paid to those who exceed the month's sales target. Bonus calculation 
      is based on the amount by which the target sales are exceeded.

      Receives: monthly_sales (double); SALES_TARGET, BONUS_RATE (const doubles);
                in this order
      Constants: SALES_TARGET, BONUS_RATE
      Returns: bonus (double)
*/

double calcBonus(double monthly_sales, const double SALES_TARGET, const double BONUS_RATE)
{
    double bonus;

    if (monthly_sales > SALES_TARGET)

        bonus = (monthly_sales - SALES_TARGET) * BONUS_RATE;

    else
        bonus = 0.00;

    return bonus;
}
/*
      Function:  calcEarnings

      The typed function, calcEarnings, calculates total earnings.

      Receives: commission (double), bonus (double); in this order
      Constants: none
      Returns: earnings (double)
*/

double calcEarnings(double commission, double bonus)
{
    double earnings;
    earnings = commission + bonus;

    return earnings;
}

/*
      Function:  printReport

      The void function, printReport, prints to an output file the employees' ID,
      monthly sales, comment indicating whether or not sales goal was  met, 
      commission earned, bonus earned, and total earnings in tablular form.
      
      e.g.
                               Monthly Sales Report

      Sales ID#      Sales    Comments   Commission     Bonus   Earnings
      ___________________________________________________________________

         39808    35000.00    Met Goal     3500.00     150.00    3650.00
         45820    28000.00                 2800.00       0.00    2800.00
      ...

      Note: printReport ONLY prints each employee record. Report title and 
            column headers are printed in a different function.

      Receives: output file variable; employee_id (int), monthly_sales (double); 
                SALES_TARGET (const double); commission (double); bonus (double); 
                earnings (double); in this order
      Constants: SALES_TARGET
      Returns: nothing - prints monthly sales results for each employee
*/

void printReport(ofstream &fout, int employee_id, double monthly_sales, const double SALES_TARGET,
                 double commission, double bonus, double earnings)
{

    if(monthly_sales >= SALES_TARGET)
    fout << fixed << setprecision(2) << setw(8)
    << employee_id << setw(12) << monthly_sales << setw(10) << "Goal met"
         << setw(12) << commission << setw(10) << bonus << setw(12) << earnings << endl;

    else
        fout << fixed << setprecision(2) << setw(8)
             << employee_id << setw(12) << monthly_sales << setw(10) << " "
             << setw(12) << commission << setw(10) << bonus << setw(12) << earnings << endl;
}
/*
    Function: printFileNotification

    The void function, printFileNotification, prints a statement to the screen
    letting the user know the name of the data file to which the sales
    report has been written.
    
    e.g. "The sales report has been written to prog5_?out.txt." 
         (without quotation marks); 
         Note: question mark is replaced with author's lecture section #
         
    Receives:  nothing
    Constants: none
    Returns:   nothing - prints file notice to the console screen
*/

void printFileNotification(ostream &cout)
{
    cout << "The sales report has been written to prog5_501out.txt." << endl;
}

