/*
 * Author: Md Ali (Димитрий Али)
 * Program: Program1_Ali
 * Course: CS2308
 * xXx_SpicyBoiii_xXx #ХакерБой
 */

#include <iostream> // Console Input/Output
#include <string>  // String Inputs
#include <fstream> // Writing to Files

using namespace std;

class Student  // Object created to hold student's ID, name, and e-mail
{
private:
    long long int student_ID;
    string student_name,
            student_email;
public:
    Student() // Default
    {
        student_ID = -1;
        student_name = "xXx_SpicyBoiii_xXx";
        student_email = "SpicyBoiii@txstate.edu";
    }

    void setID(long long int ID) // Set's ID from user input
    {
        student_ID = ID;
    }

    void setName(string name) // Set's name from user input
    {
        student_name = name;
    }

    void setEmail(string email) // Set's e-mail from user input
    {
        student_email = email;
    }

    long int getID() // Retrieves student's ID
    {
        return student_ID;
    }

    string getName() // Retrieves student's name
    {
        return student_name;
    }

    string getEmail() // Retrieves student's e-mail
    {
        return student_email;
    }
};

int main()
{

    long long int searching_ID;

    int SIZE, // 'SIZE' inputted from the user and set the amount for an array
        first, // Used in binary search
        last,
        middle;

    bool swap, // Used swapping in bubble sort
         found = false; // Used in sequential search

    char exit; // Exit out of loop from user input

    ofstream myfileUnsorted, // Opening multiple file streams to write data from array
            myfileSorted,
            myfileSSearch,
            myfileBinarySearch;

    myfileUnsorted.open("Unsorted_Student_List.txt"); // Placing an output file for each list of students
    myfileSorted.open("Sorted_Student_List.txt");
    myfileSSearch.open("Sequential_Searched_Students_List.txt");
    myfileBinarySearch.open("Binary_Searched_Students.txt");

    // Displays error message just in case files are trying to write to ROM
    if(!myfileUnsorted)
    {
        cout << "Trying to write to ROM (READ ONLY MEMORY)" << endl
             << "!!!PROGRAM TERMINATED!!!" << endl;

        return 1;
    }

    if(!myfileSorted)
    {
        cout << "Trying to write to ROM (READ ONLY MEMORY)" << endl
             << "!!!PROGRAM TERMINATED!!!" << endl;

        return 2;
    }

    if(!myfileSSearch)
    {
        cout << "Trying to write to ROM (READ ONLY MEMORY)" << endl
             << "!!!PROGRAM TERMINATED!!!" << endl;

        return 3;
    }

    if(!myfileBinarySearch)
    {
        cout << "Trying to write to ROM (READ ONLY MEMORY)" << endl
             << "!!!PROGRAM TERMINATED!!!" << endl;

        return 4;
    }

    // Prompting user on student count
    cout << "Please enter the amount of students information you will enter: ";
    cin >> SIZE;

    Student dummy, // dummy variable for bubble sort
            StudentInfo[SIZE]; // The array to hold objects of 'StudentInfo'

    // Loop to get information about each student from user
    for (int counter = 0; counter < SIZE; counter++)
    {
        long long int ID;

        string name,
                email;

        cout << "Please enter student's " << counter + 1 << " ID: ";
        cin >> ID;
        StudentInfo[counter].setID(ID);
        cout << "Please enter student's " << counter + 1 << " name (Last,First): ";
        cin >> name;
        StudentInfo[counter].setName(name);
        cout << "Please enter student's " << counter + 1 << " e-mail: ";
        cin >> email;
        StudentInfo[counter].setEmail(email);

        if (counter + 1 != SIZE)
        {
            cout << "Press any key for the next student." << endl;
            cin.ignore();
            cin.get();
        }
        else
        {
            cout << "You have entered all students information." << endl << endl;

            myfileUnsorted << "!!!UNSORTED LIST OF STUDENTS!!!" << endl
                           << "Number of Students: " << SIZE << endl << endl;
        }
    }

    for (int index = 0; index < SIZE; index++) // Writing array of students into "Unsorted_Student_List.txt"
    {
        myfileUnsorted << "Student ID: " << StudentInfo[index].getID()
                       << endl << "Student Name: " << StudentInfo[index].getName()
                       << endl << "Student E-Mail: " << StudentInfo[index].getEmail()
                       << endl << endl;
    }

    // Bubble Sort
    do {
        swap = false;
        for (int count = 0; count < SIZE - 1; count++) {
            if (StudentInfo[count].getID() > StudentInfo[count + 1].getID()) {
                dummy = StudentInfo[count];
                StudentInfo[count] = StudentInfo[count + 1];
                StudentInfo[count + 1] = dummy;
                swap = true;
            }
        }
    } while (swap);

    myfileSorted << "!!!SORTED LIST OF STUDENTS!!!" << endl
                 << "Number of Students: " << SIZE << endl << endl;

    for (int index = 0; index < SIZE; index++)  // Writing array of student into "Sorted_Student_List.txt"
    {
        myfileSorted << "Student ID: " << StudentInfo[index].getID()
                     << endl << "Student Name: " << StudentInfo[index].getName()
                     << endl << "Student E-Mail: " << StudentInfo[index].getEmail()
                     << endl << endl;
    }

    // Sequential search algorithm, if student is found write student info to "Sequential_Searched_Students_List.txt"
    myfileSSearch << "!!!SEQUENTIAL SEARCHED STUDENT!!!" << endl << endl;

    do
    {
        {
            cout << "Enter the student ID to sequentially search for: ";
            cin >> searching_ID;

            do
            {
                for (int count = 0; count < SIZE; count++)
                {
                    if (searching_ID == StudentInfo[count].getID())
                    {
                        found = true;
                        myfileSSearch << "Student ID: " << StudentInfo[count].getID()
                                      << endl << "Student Name: " << StudentInfo[count].getName()
                                      << endl << "Student E-Mail: " << StudentInfo[count].getEmail()
                                      << endl << endl;

                        cout << "Student has been recorded in 'Sequential_Searched_Students_List.txt'" << endl;

                        break;
                    }
                }
                if(found == false)
                {
                    cout << "Student not found" << endl;
                    break;
                }
                found = false;
            } while (found);

        }

        cout << "Press 'N' to stop searching for students or press any other key to continue" << endl;
        cin >> exit;

    } while(exit != 'n' and exit != 'N');

    // Binary search algorithm, if student is found write student info to "Binary_Searched_Students_List.txt"
    first = 0;
    last = SIZE - 1;
    middle = (first + last)/2;

    myfileBinarySearch << "!!!BINARY SEARCHED STUDENTS!!!" << endl << endl;

    do
    {
        cout << "Enter the student ID to binary search for: ";
        cin >> searching_ID;

        while(first <= last)
        {
            if (StudentInfo[middle].getID() < searching_ID)
            {
                first = middle + 1;
            }
            else if (StudentInfo[middle].getID() == searching_ID)
            {
                myfileBinarySearch << "Student ID: " << StudentInfo[middle].getID()
                                   << endl << "Student Name: " << StudentInfo[middle].getName()
                                   << endl << "Student E-Mail: " << StudentInfo[middle].getEmail()
                                   << endl << endl;

                cout << "Student has been recorded in 'Binary_Searched_Students_List.txt'" << endl;
                break;
            }
            else
            {
                last = middle - 1;
            }

            middle = (first+last)/2;

        }
        if(first > last)
        {
            cout << "Student not found" << endl;
        }

        first = 0;
        last = SIZE - 1;

        cout << "Press 'N' to stop searching for students or press any other key to continue" << endl;
        cin >> exit;

    }while(exit != 'n' and exit != 'N');

    // Let's the user know where the files were written to
    cout << "The unsorted list of students has been written to 'Unsorted_Student_List.txt'" << endl
         << "The sorted list of students has been written to 'Sorted_Student_List.txt'" << endl
         << "The sequential searched students has been written to 'Sequential_Searched_Students_List.txt'" << endl
         << "The binary search students has been written to 'Binary_Searched_Students_List.txt'" << endl;

    //Close all open files
    myfileUnsorted.close();
    myfileSorted.close();
    myfileSSearch.close();
    myfileBinarySearch.close();

    return 0;
}