//
// Created by Md Ali on 7/13/18.
// InfoDataTypes.cpp

/*
 * ALL FUNCTIONS HERE DO EXACTLY THE SAME THING.
 * In contrast, all function will receive the correct data type,
 * if incorrect data type is inserted, an error message will arise
 * and the user will have to input the correct data type otherwise the
 * message will repeat. All functions will take its respective data
 * type and print our the use input, address of the data type, and
 * the size in bytes of the data type.
 */

#include <iostream>
#include "Menu.h"

bool valid;

using namespace std;

void IntInfo()
{
        int num;

        while (!valid)
        {
            valid = true; //Assume the cin will be an integer.

            cout << "Enter an integer value: ";
            cin >> num;

            if(cin.fail()) //cin.fail() checks to see if the value in the cin
                           //stream is the correct type, if not it returns true,
                           //false otherwise.
            {
                cin.clear(); //This corrects the stream.
                cin.ignore(); //This skips the left over stream data.

                cout << "Please enter an Integer only." << endl;

                valid = false; //The cin was not an integer so try again.
            }

        }
    valid =  false;
        cout << "You entered: " << num << endl
             << "The address of integer " << num << " is: " << long(&num) << endl
             << "The size of " << num << " in bytes is: " << sizeof(num)  << endl;



}

void BoolInfo()
{
    bool logic;

    while (!valid)
    {
        valid = true; //Assume the cin will be an boolean.

        cout << "Enter an bool value: ";
        cin >> logic;

        if(cin.fail()) //cin.fail() checks to see if the value in the cin
                        //stream is the correct type, if not it returns true,
                        //false otherwise.
        {
            cin.clear(); //This corrects the stream.
            cin.ignore(); //This skips the left over stream data.

            cout << "Please enter an Boolean only." << endl;

            valid = false; //The cin was not an integer so try again.
        }

    }
    valid =  false;
    cout << "You entered: " << logic << endl
         << "The address of boolean " << logic << " is: " << long(&logic) << endl
         << "The size of " << logic << " in bytes is: " << sizeof(logic)  << endl;
}

void CharInfo()
{
    char n;

    while (!valid)
    {
        valid = true; //Assume the cin will be an character.

        cout << "Enter an char value: ";
        cin >> n;

        if(cin.fail()) //cin.fail() checks to see if the value in the cin
                      //stream is the correct type, if not it returns true,
                     //false otherwise.
        {
            cin.clear(); //This corrects the stream.
            cin.ignore(); //This skips the left over stream data.

            cout << "Please enter an Character only." << endl;

            valid = false; //The cin was not an integer so try again.
        }

    }
    valid =  false;
    cout << "You entered: " << n << endl
         << "The address of character " << n << " is: " << long(&n) << endl
         << "The size of " << n << " in bytes is: " << sizeof(n)  << endl;
}

void ShortInfo()
{
    short int ShortStack;

    while (!valid)
    {
        valid = true; //Assume the cin will be an short integer.

        cout << "Enter an short value: ";
        cin >> ShortStack;

        if(cin.fail()) //cin.fail() checks to see if the value in the cin
                      //stream is the correct type, if not it returns true,
                     //false otherwise.
        {
            cin.clear(); //This corrects the stream.
            cin.ignore(); //This skips the left over stream data.

            cout << "Please enter an Short only." << endl;

            valid = false; //The cin was not an integer so try again.
        }

    }
    valid =  false;
    cout << "You entered: " << ShortStack << endl
         << "The address of short " << ShortStack << " is: " << long(&ShortStack) << endl
         << "The size of " << ShortStack << " in bytes is: " << sizeof(ShortStack)  << endl;
}

void LongIntInfo()
{
    long int Lnum;

    while (!valid)
    {
        valid = true; //Assume the cin will be an long integer.

        cout << "Enter an long integer value: ";
        cin >> Lnum;

        if(cin.fail()) //cin.fail() checks to see if the value in the cin
                      //stream is the correct type, if not it returns true,
                      //false otherwise.
        {
            cin.clear(); //This corrects the stream.
            cin.ignore(); //This skips the left over stream data.

            cout << "Please enter an Long Integer only." << endl;

            valid = false; //The cin was not an integer so try again.
        }

    }
    valid =  false;
    cout << "You entered: " << Lnum << endl
         << "The address of long integer " << Lnum << " is: " << long(&Lnum) << endl
         << "The size of " << Lnum << " in bytes is: " << sizeof(Lnum)  << endl;
}

void LongFloatInfo()
{
    float Lfloat; // No such thing as a Long Float in C++

    while (!valid)
    {
        valid = true; //Assume the cin will be an float.

        cout << "Enter an long float value: ";
        cin >> Lfloat;

        if(cin.fail()) //cin.fail() checks to see if the value in the cin
                      //stream is the correct type, if not it returns true,
                     //false otherwise.
        {
            cin.clear(); //This corrects the stream.
            cin.ignore(); //This skips the left over stream data.

            cout << "Please enter an Long Float only." << endl;

            valid = false; //The cin was not an integer so try again.
        }

    }
    valid =  false;
    cout << "You entered: " << Lfloat << endl
         << "The address of long float " << Lfloat << " is: " << long(&Lfloat) << endl
         << "The size of " << Lfloat << " in bytes is: " << sizeof(Lfloat)  << endl;
}

void DoubleInfo()
{
    double DDnum;

    while (!valid)
    {
        valid = true; //Assume the cin will be an double.

        cout << "Enter an double integer value: ";
        cin >> DDnum;

        if(cin.fail()) //cin.fail() checks to see if the value in the cin
                      //stream is the correct type, if not it returns true,
                      //false otherwise.
        {
            cin.clear(); //This corrects the stream.
            cin.ignore(); //This skips the left over stream data.

            cout << "Please enter an Double Integer only." << endl;

            valid = false; //The cin was not an integer so try again.
        }

    }
    valid =  false;
    cout << "You entered: " << DDnum << endl
         << "The address of double integer " << DDnum << " is: " << long(&DDnum) << endl
         << "The size of " << DDnum << " in bytes is: " << sizeof(DDnum)  << endl;
}

void LongDoubleInfo()
{
    long double LDDnum;

    while (!valid)
    {
        valid = true; //Assume the cin will be an long double.

        cout << "Enter an long double integer value: ";
        cin >> LDDnum;

        if(cin.fail()) //cin.fail() checks to see if the value in the cin
                      //stream is the correct type, if not it returns true,
                      //false otherwise.
        {
            cin.clear(); //This corrects the stream.
            cin.ignore(); //This skips the left over stream data.

            cout << "Please enter an Long Double Integer only." << endl;

            valid = false; //The cin was not an integer so try again.
        }

    }
    valid =  false;
    cout << "You entered: " << LDDnum << endl
         << "The address of long double integer " << LDDnum << " is: " << long(&LDDnum) << endl
         << "The size of " << LDDnum << " in bytes is: " << sizeof(LDDnum)  << endl;
}

void DoubleArrayInfo()
{
    double DDnumArray[5];

    while (!valid)
    {
        valid = true; //Assume the cin will be an double.

        cout << "Enter an  5 double integer value into the array: ";
        for(int count = 0; count < 5; count++)
        {
            cin >> DDnumArray[count];
            if (cin.fail()) //cin.fail() checks to see if the value in the cin
                           //stream is the correct type, if not it returns true,
                           //false otherwise.
            {
                cin.clear(); //This corrects the stream.
                cin.ignore(); //This skips the left over stream data.

                cout << "Please enter an Double Integer only. Array has reset. "
                        " Press any key to continue" << endl;

                valid = false; //The cin was not an integer so try again.
            }
        }
    }

    valid =  false;

    cout << "You entered: ";
    for(int count = 0; count < 5; count++)
    {
        cout << DDnumArray[count] << " ";
    }

    cout << endl << "The address of the double integer array is: "
         << long(&DDnumArray) << endl
         << "The size of the double integer array in bytes is: "
            << sizeof(DDnumArray) << endl;
}

void IntArrayInfo()
{
    int numArray[4];

    while (!valid)
    {
        valid = true; //Assume the cin will be an integer.

        cout << "Enter an 4 integer value into the array: ";
        for(int count = 0; count < 4; count++)
        {
            cin >> numArray[count];
            if (cin.fail()) //cin.fail() checks to see if the value in the cin
                           //stream is the correct type, if not it returns true,
                          //false otherwise.
            {
                cin.clear(); //This corrects the stream.
                cin.ignore(); //This skips the left over stream data.

                cout << "Please enter an Integer only. Array has reset. "
                        "Press any key to continue" << endl;

                valid = false; //The cin was not an integer so try again.
            }
        }
    }
    valid =  false;

    cout << "You entered: ";
    for(int count = 0; count < 4; count++)
    {
        cout << numArray[count] << " ";
    }

    cout << endl << "The address of the integer array is: "
         << long(&numArray) << endl
         << "The size of the integer array in bytes is: "
         << sizeof(numArray) << endl;
}

void PointerPointIntInfo()
{
    int num;
    int *ptrInt;

    while (!valid)
    {
        valid = true; //Assume the cin will be an integer.

        cout << "Enter an integer value: ";
        cin >> num;
        ptrInt = &num;

        if(cin.fail()) //cin.fail() checks to see if the value in the cin
                       //stream is the correct type, if not it returns true,
                       //false otherwise.
        {
            cin.clear(); //This corrects the stream.
            cin.ignore(); //This skips the left over stream data.

            cout << "Please enter an Integer only." << endl;

            valid = false; //The cin was not an integer so try again.
        }

    }
    valid =  false;

    cout << "You entered: " << num << endl
         << "The address of the pointer variable pointing to the integer "
            << num << " is: " << long(&ptrInt) << endl
         << "The size of " << ptrInt << " in bytes is: " << sizeof(ptrInt)  << endl;
}

void PointerPointFloatInfo()
{
    float num;
    float *ptrFloat;

    while (!valid)
    {
        valid = true; //Assume the cin will be an float.

        cout << "Enter an float integer value: ";
        cin >> num;
        ptrFloat = &num;

        if(cin.fail()) //cin.fail() checks to see if the value in the cin
                       //stream is the correct type, if not it returns true,
                      //false otherwise.
        {
            cin.clear(); //This corrects the stream.
            cin.ignore(); //This skips the left over stream data.

            cout << "Please enter an Float Integer only." << endl;

            valid = false; //The cin was not an integer so try again.
        }

    }
    valid =  false;

    cout << "You entered: " << num << endl
         << "The address of the pointer variable pointing to the float "
         << num << " is: " << long(&ptrFloat) << endl
         << "The size of " << ptrFloat << " in bytes is: " << sizeof(ptrFloat)  << endl;
}
