/*
# FILE: Caesar_Sipher.cpp
# USAGE: Must be compiled and user interaction.
# DESCRIPTION: This is a basic Caesar sipher code in C++. This will take in a message from the user and then asks the user how many charaters to shift the code. From there the encoded message will be printed. 
# OPTIONS: --
# REQUIREMENTS: -- 
# BUGS: -- 
# AUTHOR: xXxSpicyBoiiixXx
# ORGANIZATION: -- 
# VERSION: 1.0
# CREATED: 08/30/2018
# REVISION: --
*/

#include <iostream>

using namespace std;

string encodeCaesarCipher(string str, int shift);

int main()
{
    string str, encoded_string;
    int shift;

    cout << "This program encodes a message in Caesar Cipher." << endl;

    cout << "Please enter a message: ";
    getline(cin, str);

    cout << "How many times do you want to shift the letter(s) in the message? ";
    cin >> shift;

    while (shift < 1)
    {
        cout << "You have entered an invalid number." << endl;
        cout << "Please try again." << endl;
        cout << "Enter a proper number for the amount of letter shifting: ";
        cin >> shift;
    }

    encoded_string = encodeCaesarCipher(str, shift);

    cout << "Encoded message: " << encoded_string << endl;

    system("PAUSE");

    return 0;
}

string encodeCaesarCipher(string str, int shift)
{
    string temp = str;
    int length;

    length = (int)temp.length();

    for (int i = 0; i < length; i++)
    {
        if (isalpha(temp[i]))
        {
            for (int j = 0; j < shift; j++)
            {
                if (temp[i] == 'z')
                {
                    temp[i] = 'a';
                }
                else if (temp[i] == 'Z')
                {
                    temp[i] = 'A';
                }
                else
                {
                    temp[i]++;
                }
            }
        }
    }

    return temp;
}
