/*
================================================================================
            COLLEGE DORM ADMISSION THROUGH COUPONS (CDAC) SYSTEM

Developed by:
MUHAMAD ADIB ASYRAAF BIN AZIS	            2023126433	RCDCS2513B	CS251
MUHAMMAD KHAIRUL HAZIQ BIN MOHAMAD KHAIRI	2023164629	RCDCS2513B	CS251
MUHAMMAD 'ARIF BIN SALLEH HUDIN	            2023389011  RCDCS2513B	CS251
MUHAMMAD AYSAR BIN MAHMAD YUSUP	            2023189277	RCDCS2513B	CS251

Course: CSC404 Programming II

The CDAC system is an application developed to manage the distribution and
accumulation of activity-based coupons in a college setting. Students can
earn coupons by participating in university activities. Accumulating a
certain number of these coupons qualifies them for college dorm admission.

================================================================================
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <stdexcept>

using namespace std;

// Struct
struct Student
{
    string id;
    string name;
    int coupons;
};

struct Activity
{
    string id;
    string name;
};

// Global Variables
const int MAX_ACTIVITIES = 10;
const int MAX_STUDENTS = 50;
const int MAX_STUDENTS_ACTIVITIES = 50;
const string STUDENTS_FILE = "../data/students.txt";
const string ACTIVITIES_FILE = "../data/activities.txt";

int numStudents = 0;
Student students[MAX_STUDENTS];

int numActivities = 0;
Activity activities[MAX_ACTIVITIES];

int coupon[MAX_STUDENTS_ACTIVITIES][MAX_STUDENTS_ACTIVITIES] = {0};

// User-defined Functions
void loadStudents()
{
    ifstream inputFile(STUDENTS_FILE);
    if (!inputFile)
    {
        throw runtime_error("Unable to open students file for reading.");
    }

    string line;
    while (getline(inputFile, line))
    {
        stringstream ss(line);
        string id, name;
        int coupons;

        getline(ss, id, ',');
        getline(ss, name, ',');
        ss >> coupons;

        students[numStudents] = {id, name, coupons};
        coupon[numStudents][0] = coupons;
        numStudents++;
    }
    inputFile.close();
}
void loadActivities()
{
    ifstream inputFile(ACTIVITIES_FILE);
    if (!inputFile)
    {
        throw runtime_error("Unable to open activities file for reading.");
    }

    numActivities = 0;
    string line;
    while (getline(inputFile, line))
    {
        stringstream ss(line);

        getline(ss, activities[numActivities].id, ',');
        getline(ss, activities[numActivities].name, ',');
        coupon[0][numActivities] = 0;
        numActivities++;
    }
    inputFile.close();
}

void saveStudents()
{
    ofstream outputFile(STUDENTS_FILE);
    for (int i = 0; i < numStudents; i++)
    {
        outputFile << students[i].id << ',' << students[i].name << ',' << students[i].coupons << '\n';
    }
    outputFile.close();
}

Student *findStudentById(const string &id)
{
    for (int i = 0; i < numStudents; i++)
    {
        if (students[i].id == id)
            return &students[i];
    }
    return nullptr;
}

Activity *findActivityById(const string &id)
{
    for (int i = 0; i < numActivities; i++)
    {
        if (activities[i].id == id)
            return &activities[i];
    }
    return nullptr;
}

void displayAllStudents()
{
    cout << "Registered Students:\n";
    for (int i = 0; i < numStudents; i++)
    {
        cout << "ID: " << students[i].id << ", Name: " << students[i].name << ", Coupons: " << students[i].coupons << '\n';
    }
    cout << endl;
}

void displayAllActivities()
{
    cout << "Registered Activities:\n";
    for (int i = 0; i < numActivities; i++)
    {
        cout << "ID: " << activities[i].id << ", Name: " << activities[i].name << '\n';
    }
    cout << endl;
}
int findStudentIndex(const Student *student)
{
    for (int i = 0; i < numStudents; i++)
    {
        if (&students[i] == student)
        {
            return 1;
        }
    }
    return -1;
}

int findActivityIndex(const Activity *activity)
{
    for (int i = 0; i < numActivities; i++)
    {
        if (&activity[i] == activity)
        {
            return 1;
        }
    }
    return -1;
}

void displayCouponCount()
{
    string id;
    cout << "Enter student ID: ";
    cin >> id;
    cin.ignore();

    Student *student = findStudentById(id);
    if (student)
    {
        cout << "Coupon Counts for Student ID " << student->id << ":\n";
        for (int i = 0; i < numActivities; i++)
        {
            int studentIndex = findStudentIndex(student);
            int activityIndex = findActivityIndex(&activities[i]);
            cout << "Activity ID: " << activities[i].id << ", Coupons: " << coupon[studentIndex][activityIndex] << '\n';
        }
    }
    else
    {
        cout << "Student not found!\n";
    }
    cout << endl;
}

void displayMenu()
{
    cout << "Welcome to College Dorm Admission through Coupons (CDAC) System!\n";
    cout << "1 - Register a new student\n";
    cout << "2 - Add an activity coupon to a student\n";
    cout << "3 - Check current dorm eligibility status\n";
    cout << "4 - View all registered students\n";
    cout << "5 - View all registered activities\n";
    cout << "6 - View coupon counts\n";
    cout << "7 - Exit\n";
    cout << "Enter your choice: ";
}

int main()
{
    try
    {
        loadStudents();
        loadActivities();
    }
    catch (const runtime_error &e)
    {
        std::cerr << e.what() << '\n';
    }

    while (true)
    {
        int choice;
        displayMenu();
        cin >> choice;

        if (choice == 1)
        {
            string id, name;
            cout << "Enter student ID: ";
            cin >> id;
            cin.ignore();

            cout << "Enter student name: ";
            getline(cin, name);

            students[numStudents] = {id, name, 0};
            numStudents++;
            saveStudents();

            cout << "Student registered!\n";
            cout << endl;
        }
        else if (choice == 2)
        {
            string stuId, actId;
            cout << "Enter student ID: ";
            cin >> stuId;

            Student *student = findStudentById(stuId);
            if (student)
            {
                displayAllActivities();
                cout << "Enter the activity ID that the student join: ";
                cin >> actId;

                Activity *activity = findActivityById(actId);
                if (activity)
                {
                    int studentIndex = findStudentIndex(student);
                    int activityIndex = findActivityIndex(activity);
                    student->coupons++;
                    coupon[studentIndex][activityIndex]++;
                    saveStudents();
                    cout << "Coupon added!\n";
                }
                else
                {
                    cout << "Activity not found!\n";
                }
            }
            else
            {
                cout << "Student not found!\n";
            }
            cout << endl;
        }
        else if (choice == 3)
        {
            string id;
            cout << "Enter student ID: ";
            cin >> id;
            Student *student = findStudentById(id);
            if (student)
            {
                if (student->coupons >= 10)
                {
                    cout << "Student is eligible for dorm admission!\n";
                }
                else
                {
                    cout << "Student is not eligible for dorm admission.\n";
                }
            }
            else
            {
                cout << "Student not found!\n";
            }
            cout << endl;
        }
        else if (choice == 4)
        {
            displayAllStudents();
        }
        else if (choice == 5)
        {
            displayAllActivities();
        }
        else if (choice == 6)
        {
            displayCouponCount();
        }
        else if (choice == 7)
        {
            cout << "Exiting the program.\n";
            break;
        }
        else
        {
            cout << "Invalid choice. Please enter from 1 to 6!\n";
        }
    }
    return 0;
}