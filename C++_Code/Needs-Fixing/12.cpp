#include <iostream>
#include <iomanip>

using namespace std;

  const int ADULT_MEAL_COST = 6.25,
    CHILD_MEAL_COST = (0.75*ADULT_MEAL_COST),
    TX_Tax = 0.0825;

int main()
{
    int numAdults,
        numChildren;

        double adultmealtotal,
            childmealtotal,
            totalmealtotal;

            cout << "This program calculates total cost to feed your fatass.\n";
            cout << "Enter the number of adults guest (ages 12 or over): ";
            cin >> numAdults;
            cout << "Enter the number of mini yous (ages 11 or under): ";
            cin >> numChildren;

            adultmealtotal = numAdults*ADULT_MEAL_COST;
            childmealtotal = numChildren*CHILD_MEAL_COST;
            totalmealtotal = adultmealtotal+childmealtotal;
            cout << "PAY UP BITCH " << ((totalmealtotal) * TX_Tax ) + totalmealtotal<< endl;


    return 0;
}
