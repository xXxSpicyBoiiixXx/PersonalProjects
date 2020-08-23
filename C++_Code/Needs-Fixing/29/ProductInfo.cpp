//
// Created by Spicy Boiii on 7/17/18.
//
#include <iostream>
#include <fstream>
#include <string>

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
