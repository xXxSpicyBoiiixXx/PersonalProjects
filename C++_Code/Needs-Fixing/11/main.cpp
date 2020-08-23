/*
 * Author: Md Ali (Димитрий Али)
 * Program: Program2_Ali
 * Course: CS2308
 * xXx_SpicyBoiii_xXx #ХакерБой
 */

//main.cpp

#include <iostream>
#include "Menu.h"
#include "OutputDataTypeInfo.h"

using namespace std;

int main() {

    char cont;

    int input;

    //Do while loop for continuous user input
    do
    {
        MenuOptionDataTypes();
        input = MenuChoice();
        cont = OutputInfo(input);

    }while (input != 13 and cont != 'n' and cont != 'N');

    ExitStatement();

}