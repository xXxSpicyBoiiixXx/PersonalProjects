#include <iostream>
#include <fstream>
#include "Loan.h"


using namespace std;


int main()
{
    Loan temp_loan;

    char cont;

    int input,
        input_year;

    double input_cost,
           input_rate,
           term_rate,
           month_payment;

    ofstream outputfile;
    outputfile.open("MonthlyPayment.txt");

    do
    {
        Menu();
        input = MenuChoice();
        if(input == 1)
        {
            cout << "CAR LOAN" << endl << endl;

            cout << "Enter the number of years: ";
            cin >> input_year;
            cout << "Enter the cost: ";
            cin >> input_cost;
            cout << "Enter the interest rate: ";
            cin >> input_rate;

            temp_loan.Car_Loan(input_year,input_cost,input_rate);

        }

        else if(input == 2)
        {
            cout << "MORTGAGE LOAN" << endl << endl;

            cout << "Enter the number of years: ";
            cin >> input_year;
            cout << "Enter the cost: ";
            cin >> input_cost;
            cout << "Enter the interest rate: ";
            cin >> input_rate;

            temp_loan.Mortgage_Loan(input_year,input_cost,input_rate);
        }

        else
        {
            cout << "You have exited the program" << endl;
            return 1;
        }

        term_rate = calc_term(input_year, input_rate);

        month_payment = calc_payment(input_cost, input_rate, term_rate);

        outputfile << "Your monthly payments are " << month_payment
                   << " for a loan of " << input_cost << " with an interest rate of "
                   << input_rate << "% for " << input_year << " years." << endl;

        cout << "Your information was stored in MonthlyPayment.txt" << endl;

        cout << "Press any key to continue to add more loans or press N  to quit" << endl;
        cin >> cont;

    }while(input != 3 and cont != 'n' and cont != 'N');

    cout << "You have exited the program.";

    return 0;
}