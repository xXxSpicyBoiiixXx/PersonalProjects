/*
* Author: Md Ali (Димитрий Али)
* Program: Program7_Ali
* Course: CS2308
* xXx_SpicyBoiii_xXx #ХакерБой
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include "StudnetInfo.h"

using namespace std;

int main()
{
    bool swap;

    ofstream StudentInfoFile;
    StudentInfoFile.open("StudentInfo.txt");

    if(!StudentInfoFile)
    {
        cout << "Trying to write to ROM (READ ONLY MEMORY)" << endl;

        return 1;
    }

    int SIZE = inputStudents();
    StudentInfo studentList[SIZE];

    int numOfTest = inputTests();

    for(int count = 0; count < SIZE; count++)
    {
        studentList[count].name = inputName();
        studentList[count].ID = inputID();
        studentList[count].tests = inputScores(numOfTest);
        studentList[count].final = inputFinal(20);
    }


    for(int count = 0; count < SIZE; count++)
    {
        studentList[count].average = 0.6 * calcAverage(studentList[count].tests, numOfTest)
                + 0.4 * studentList[count].getFinal();
    }


    do {
        StudentInfo dummy;
        swap = false;
        for (int count = 0; count < SIZE - 1; count++) {
            if (studentList[count].getID() > studentList[count + 1].getID()) {
                dummy = studentList[count];
                studentList[count] = studentList[count + 1];
                studentList[count + 1] = dummy;
                swap = true;
            }
        }
    } while (swap);

    StudentInfoFile << "Student Name   Student ID";

    for (int count = 1; count <= numOfTest; count++)
    {
        StudentInfoFile << "  Exam " << count ;
    }



    StudentInfoFile << "  Final    " << "  Average" << endl;

    for(int index = 0; index < SIZE; index++)
    {

        StudentInfoFile << studentList[index].getName() << "  "
                        << studentList[index].getID() << "  "
        << studentList[index].getScores(StudentInfoFile,numOfTest) << "  "
                << setprecision(4) << studentList[index].getAverage() << "  ";
         StudentInfoFile << calcGrade(studentList, studentList[index].getAverage()) << endl;
    }

    StudentInfoFile.close();

    cout << "All Students info has been written to 'StudentInfoFile.txt'" << endl;


    return 0;
}