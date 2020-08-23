//
// Created by Spicy Boiii on 8/6/18.
//
#include <iostream>
#include <string>
#include <fstream>
#include "StudnetInfo.h"

using namespace std;


int inputStudents()
{
    int students;
    cout << "How many students are there?" << endl;
    cin >> students;

    return students;
}

int inputTests()
{
    int tests;
    cout << "How many tests will there be?" << endl;
    cin >> tests;

    return tests;
}

string inputName()
{
    string name;
    cout << "Enter the student's name: ";
    cin >> name;

    return name;
}

int inputID()
{
    int ID;
    cout << "Enter the student's ID Number: ";
    cin >> ID;

    return ID;
}

int *inputScores(int numOfTests)
{
    int *scores;
    scores = new int[numOfTests];

    cout << "Enter the test scores for the student. Press ENTER after each entry." << endl;

    for (int count = 0; count < numOfTests; count++)
    {
        cout << "Score " << count + 1 << ": ";
        cin >> scores[count];
    }

    return scores;

}

int inputFinal(int numOfProb)
{
    int numMiss,
            final;
    cout << "Enter the number missed on the final by the student.";
    cin >> numMiss;
    final = (numOfProb - numMiss) * 5;

    return final;

}

double calcAverage(int *testScores, int numOfTests)
{
    double total = 0;
    double average;

    for(int count = 0; count < numOfTests; count++)
    {
        total+= testScores[count];
    }

    average = 0.6 * (total/numOfTests);

    return average;
}

void calcGrade(ofstream &outputFile, double average)
{
    if(average >= 89.5)
    {
        outputFile << "A";
    }
    else if(average >= 79.5)
    {
        outputFile << "B";
    }
    else if(average >= 69.5)
    {
        outputFile << "C";
    }
    else if(average >= 59.5)
    {
        outputFile << "D";
    }
    else
    {
        outputFile << "F";
    }
}