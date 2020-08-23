/*
 * Author: Md Ali (Димитрий Али)
 * Program: Program3_Ali
 * Course: CS2308
 * xXx_SpicyBoiii_xXx #ХакерБой
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class ProductInfo
{
private:

    string ProductName;

    double ProductPrice;

    int ProductID,
        QuantityOfProduct;
public:

    void setName(string name)
    {
        ProductName = name;
    }

    void setPrice(double money)
    {
        ProductPrice = money;
    }

    void setProductID(int ID)
    {
        ProductID = ID;
    }

    void setQuantity(int number)
    {
        QuantityOfProduct = number;
    }

    string getName()
    {
        return ProductName;
    }

    double getPrice()
    {
        return ProductPrice;
    }

    int getProductID()
    {
        return ProductID;
    }

    int getQuantity()
    {
        return QuantityOfProduct;
    }

};

int main()
{
    int SIZE;

    bool valid,
         swap;

    double sales,
           totalsales = 0;

    ProductInfo *ProductInfoptr = nullptr;
    ProductInfoptr = new ProductInfo[SIZE];

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
        bool valid1 = false,
             valid2 = false,
             valid3 = false,
             valid4 = false;

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

        ProductInfoptr[counter].setName(name);

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

        ProductInfoptr[counter].setProductID(identification);

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

        ProductInfoptr[counter].setPrice(DatMoney);

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

        ProductInfoptr[counter].setQuantity(numberOfThings);

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

    }

    outputfile << "Name         "
               << "ID       "
               << "Price        "
               << "Quantity Sold        "
               << "Sale" << endl;

    do {

        ProductInfo dummy;
        swap = false;
        for (int count = 0; count < SIZE - 1; count++) {
            if (ProductInfoptr[count].getProductID() > ProductInfoptr[count + 1].getProductID())
            {
                dummy = ProductInfoptr[count];
                ProductInfoptr[count] = ProductInfoptr[count + 1];
                ProductInfoptr[count + 1] = dummy;
                swap = true;
            }
        }
    } while (swap);

    for(int index = 0; index < SIZE; index++)
    {
        sales = ProductInfoptr[index].getPrice() * ProductInfoptr[index].getQuantity();

        outputfile << ProductInfoptr[index].getName() << "       "
                   << ProductInfoptr[index].getProductID() << "      "
                   << ProductInfoptr[index].getPrice() << "                "
                   << ProductInfoptr[index].getQuantity() << "             "
                   << setprecision(4) << sales << endl;

        totalsales += sales;
    }

    outputfile << endl << "TOTAL SALE: $" << totalsales;

    cout << "All information has been written to 'products.txt'" << endl;

    outputfile.close();

    return 0;
}