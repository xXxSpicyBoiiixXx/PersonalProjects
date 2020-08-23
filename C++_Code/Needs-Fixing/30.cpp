/*
 * Author: Md Ali (Димитрий Али)
 * Program: Program4_Ali
 * Course: CS2308
 * xXx_SpicyBoiii_xXx #ХакерБой
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct ProductsInfo
{
    string ProductName;

    int ProductID,
        QuantitySold;

    double UnitPrice;

};

int main()
{
        int SIZE;

        bool valid,
                swap;

        double sales,
                totalSales = 0;

        ProductsInfo DaProductsFam[SIZE];

        ofstream outputfile;
        outputfile.open("products.txt");

        if(!outputfile)
        {
            cout << "Unable to write to file 'products.txt'" << endl;
            return 1;
        }

        while (!valid)
        {
            valid = true; //Assume the cin will be an integer.
            cout << "Please enter the number of products you will be entering: ";
            cin >> SIZE;

            //cin.fail() checks to see if the value in the cin
            //stream is the correct type, if not it returns true,
            //false otherwise.
            if (cin.fail())

            {
                cin.clear(); //This corrects the stream.
                cin.ignore(); //This skips the left over stream data.

                cout << endl
                     << "!!!Please enter an integer value!!!"
                     << endl << endl;

                valid = false; //The cin was not an integer so try again
            }

        }

        cout << "You will be entering " << SIZE << " products" << endl;

        for(int counter = 0; counter < SIZE; counter++)
        {
            bool valid1, valid2, valid3, valid4;

            string name;

            double DatMoney;

            int identification,
                    numberOfThings;

            while (!valid1)
            {
                valid1 = true;
                cout << "Please enter the product's name: ";
                cin >> name;

                if (cin.fail())

                {
                    cin.clear();
                    cin.ignore();

                    cout << endl
                         << "!!!Please enter a string!!!"
                         << endl << endl;

                    valid1 = false;
                }

            }

            DaProductsFam[counter].ProductName = name;

            while (!valid2)
            {
                valid2 = true;
                cout << "Please enter " << name << "'s ID: ";
                cin >> identification;

                if (cin.fail())

                {
                    cin.clear();
                    cin.ignore();

                    cout << endl
                         << "!!!Please enter an integer value!!!"
                         << endl << endl;

                    valid2 = false;
                }

            }

            DaProductsFam[counter].ProductID = identification;

            while (!valid3)
            {
                valid3 = true;
                cout << "Please enter " << name << "'s price: ";
                cin >> DatMoney;

                if (cin.fail())

                {
                    cin.clear();
                    cin.ignore();

                    cout << endl
                         << "!!!Please enter an number value!!!"
                         << endl << endl;

                    valid3 = false;
                }

            }

            DaProductsFam[counter].UnitPrice = DatMoney;

            while (!valid4)
            {
                valid4 = true;
                cout << "Please enter the number of " << name << " sold: ";
                cin >> numberOfThings;

                if (cin.fail())

                {
                    cin.clear();
                    cin.ignore();

                    cout << endl
                         << "!!!Please enter an integer value!!!"
                         << endl << endl;

                    valid4 = false;
                }

            }

            DaProductsFam[counter].QuantitySold = numberOfThings;

            if(counter + 1 != SIZE)
            {
                cout << "Press any key to enter the next product's information." << endl;
                cin.ignore();
                cin.get();
            }

            else
            {
                cout << "You entered all products." << endl;
            }

            valid1 = false;
            valid2 = false;
            valid3 = false;
            valid4 = false;

        }

        outputfile << "Name" << setw(8)
                   << "ID" << setw(8)
                   << "Price" << setw(16)
                   << "Quantity Sold" << setw(8)
                   << "Sale" << endl << setfill('-') << setw(50) << "-" << endl
                   << setfill(' ');



        //Bubble Sort
        do {

            ProductsInfo dummy;
            swap = false;
            for (int count = 0; count < SIZE - 1; count++) {
                if (DaProductsFam[count].ProductID > DaProductsFam[count + 1].ProductID)
                {
                    dummy = DaProductsFam[count];
                    DaProductsFam[count] = DaProductsFam[count + 1];
                    DaProductsFam[count + 1] = dummy;
                    swap = true;
                }
            }
        } while (swap);

        for(int index = 0; index < SIZE; index++)
        {
            sales = DaProductsFam[index].UnitPrice * DaProductsFam[index].QuantitySold;

            outputfile << DaProductsFam[index].ProductName << setw(8)
                       << DaProductsFam[index].ProductID << setw(7)
                       << fixed << setprecision(2)
                       << DaProductsFam[index].UnitPrice << setw(10)
                       << DaProductsFam[index].QuantitySold << setw(10) << "$"
                       << sales << endl;

            totalSales += sales;

        }

        outputfile << endl << "TOTAL SALE: $" << totalSales;

        cout << "All information has been written to 'products.txt'" << endl;

        outputfile.close();

        return 0;
    }