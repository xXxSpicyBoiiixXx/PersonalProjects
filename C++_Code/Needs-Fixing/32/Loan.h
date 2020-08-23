 //
// Created by Spicy Boiii on 8/6/18.
//

#ifndef PROGRAM6_ALI_LOAN_H
#define PROGRAM6_ALI_LOAN_H

using namespace std;

 class Loan
 {
     int years;
     double cost,
             interest_rate;

 public:
     void Car_Loan(int y, double c, double i)
     {
         years = y;
         cost = c;
         interest_rate = i;
         cout << years << " years, $" << cost << " mortgage loan "
              << "including tax and fee, and annual interest rate: "
              << interest_rate << "%" << endl;

     }
     void Mortgage_Loan(int y, double c, double i)
     {
         years = y;
         cost = c;
         interest_rate = i;
         cout << years << " years, $" << cost << " mortgage loan "
              << "including tax and fee, and annual interest rate: "
              << interest_rate << "%" << endl;
     }

 };

void Menu();

int MenuChoice();

double calc_term(int, double);

 double calc_payment(int, double, double);

#endif //PROGRAM6_ALI_LOAN_H
