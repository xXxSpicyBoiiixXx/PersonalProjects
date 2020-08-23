#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << "Hello world!, Press 'Y' or 'N' to continue" << endl;

    char Y,N,Ans;
    cin >> Ans;

    if(Ans = 'Y')
    {
        cout << "Thanks for continuing, I'm glad you're here :)" << endl;

}     else if (Ans = 'N')
     {
         cout << "I hope you're doing alright bud" << endl;
     }
     else
            {
                cout << "You suck" << endl;

    }

   cout << endl;

    int age, n;

    cout << "Now for some real fun boiiiiiii, well not really.." << endl;
    cout << "This program will do some neat little math tricks." << endl;
    cout << "Enter your age dawg." << endl;

    cin >> n;

    while( n < 100)
        {
            cout << "Your current age is " << n << endl;
            n = n+23;
            cout << "In 23 years your age will be " << n << " from the previous statement" << endl;
        }
        if (n >= 100)
        {
            cout << "Im getting bored of this and gonna do my Pre-Lab stuff" << endl;
        }
    return 0;
}
