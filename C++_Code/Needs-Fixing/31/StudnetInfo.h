//
// Created by Spicy Boiii on 8/6/18.
//

#ifndef PROGRAM5_ALI_STUDNETINFO_H
#define PROGRAM5_ALI_STUDNETINFO_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Person
{
public:
    string name;

    string getName() { return name; }


};

class StudentInfo : public Person
{

public:
    int ID;
    int* tests;
    int final;
    double average;

    int getID() { return ID; }
    void *getScores(ofstream &outputFile, int numOfExams)
    {
        for(int i = 0; i < numOfExams; i++)
        outputFile << tests[i] <<  " ";
        }
    double getAverage() { return average; }
    int getFinal() {return final;}
};

int inputStudents();

int inputTests();

string inputName();

int inputID();

int *inputScores(int);

int inputFinal(int)

double calcAverage(int*, int);

char calcGrade(ofstream &outputFile, double);


#endif //PROGRAM5_ALI_STUDNETINFO_H
