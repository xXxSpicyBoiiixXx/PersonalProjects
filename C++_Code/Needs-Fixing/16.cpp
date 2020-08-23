#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Function Prototypes
void displayMenu();
int getChoice();
void showFees(string catergory, double rate, int months);

int main()
{
    // Constant for monthly membership rates
    const double ADULT_RATE = 120.0, CHILD_RATE = 60.0, SENIOR_RATE = 100.0;

    int choice, months;

    //Set numeric output formatting
    cout << fixed << showpoint << setprecision(2);

    do
    {
        displayMenu();
        choice = getChoice();
        // Assign choice the value returned by the getChoice
        // function if user does not want to quit, proceed

        if(choice != 4)
        {
            cout << "For how many months?" ;
            cin >> months;

            switch(choice)
            {
                case 1: showFees("Adult", ADULT_RATE, months);
                break;
                case 2: showFees("Child", CHILD_RATE, months);
                break;
                case 3: showFees("Senior", SENIOR_RATE, months);
                break;
            }
        }
    }
    while(choice != 4);

    return 0;
}

//DisplayMenu function

void displayMenu()
{
    system("cls"); //Clears the screen
    cout << "\n Health Club Memebership Menu\n\n";
    cout << "1. Standard Adult Membership\n";
    cout << "2. Child Membership\n";
    cout << "3. Senior Citizen Membership\n";
    cout << "4. GTFO outta here boiiiiii\n\n";
}

//getChoice function
int getChoice()
{

    int choice;
    cin >> choice;
    while(choice < 1 || choice > 4)
    {
        cout << "The only vaild choice are 1-4. Please re-enter....bitch";
        cin >> choice;
    }
    return choice;
}

//showFees function

void showFees(string memberType, double rate, int months)
{

    cout << endl << "Membership Type : " << memberType << "   "
    << "Number of months: " << months << endl
    << "GIVE ME DAT MONEY HOEEEEEEE: $" << (rate*months) << endl;

    // HOld the screen until the user presses the ENTER key
    cout << "\nPress the Enter key to return to menu bitch. ";
    cin.get(); // clear the previous \n out of the input buffer
    cin.get(); // Wait for the user to press ENTer
}
