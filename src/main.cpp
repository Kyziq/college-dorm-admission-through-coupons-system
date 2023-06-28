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
#include <string>
#include <vector>
#include <sstream>

using namespace std;

const string STUDENTS_FILE = "../data/students.txt";
const string ACTIVITIES_FILE = "../data/activities.txt";

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

vector<Student> loadStudents()
{
    ifstream file(STUDENTS_FILE);
    vector<Student> students;
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string id, name;
        int coupons;
        getline(ss, id, ',');
        getline(ss, name, ',');
        ss >> coupons;
        students.push_back({id, name, coupons});
    }
    return students;
}

void saveStudents(const vector<Student> &students)
{
    ofstream file(ACTIVITIES_FILE);
    for (const Student &student : students)
    {
        file << student.id << ',' << student.name << ',' << student.coupons << '\n';
    }
}

Student *findStudentById(const string &id, vector<Student> &students)
{
    for (Student &student : students)
    {
        if (student.id == id)
            return &student;
    }
    return nullptr;
}

void displayMenu()
{
    cout << "Welcome to College Dorm Admission through Coupons (CDAC) System!\n";
    cout << "1 - Register a new student\n";
    cout << "2 - Add an activity coupon to a student\n";
    cout << "3 - Check current dorm eligibility status\n";
    cout << "Enter your choice: ";
}

int main()
{
    vector<Student> students = loadStudents();

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

            students.push_back({id, name, 0});
            saveStudents(students);

            cout << "Student registered!\n";
            cout << endl;
        }
        else if (choice == 2)
        {
            string id;
            cout << "Enter student ID: ";
            cin >> id;
            Student *student = findStudentById(id, students);
            if (student)
            {
                student->coupons++;
                saveStudents(students);
                cout << "Coupon added!\n";
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
            Student *student = findStudentById(id, students);
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
    }
    return 0;
}