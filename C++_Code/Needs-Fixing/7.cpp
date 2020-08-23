/*
 * Author: Md Ali
 * C.S.1428.501
 * Lab Section: L01
 */

//Add code where requested to complete the program.

#include <iostream>
#include <fstream>


using namespace std;

struct Dog
{
    string name;
    string breed;
    char sex;
    int age;
};

int main()
{
    // TODO - Create a Dog object named "dog1", and initialize its name to
    //        "Sparky", sex to 'M', age to 5, and breed to "Collie".
    Dog dog1;

    dog1.name = "Sparky";
    dog1.sex = 'M';
    dog1.age = 5;
    dog1.breed = "Collie";

    // TODO - Create a Dog object named "dog2".
    Dog dog2;

    // TODO - Prompt the user to enter the dog's name, age, sex, and breed,
    //        and assign them to the "dog2" object.
    //        Assume the dog name and breed are entered as a single word
    //        so that both will work with cin statements.
    cout << "Enter the dog's name: ";
    cin >> dog2.name;
    cout << endl << "Enter the age of " << dog2.name << ": ";
    cin >> dog2.age;
    cout << endl << "Enter the sex of " << dog2.name << " (M/F):";
    cin >> dog2.sex;
    cout << endl << "Enter the breed of " << dog2.name << ": ";
    cin >> dog2.breed;

    // TODO - Print "dog1" and "dog2" objects to the console. E.g.
    //        "Name: Sparky, Sex: M, Age: 5, Breed: Collie"
    cout << "Name: " << dog1.name << ", Sex: " << dog1.sex << ", Age: " << dog1.age
         << ", Breed: " << dog1.breed << endl << "Name: " << dog2.name <<", Sex: "
            << dog2.sex << ", Age: " << dog2.age << ", Breed: " << dog2.breed << endl;


    return 0;
}