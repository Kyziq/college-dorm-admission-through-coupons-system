/*
College Dorm Admission through Coupons (CDAC) System

TODO:
1. Add option to exit looping for user
2. Add option to view all students registered
3. Add option to view all activities registered

*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

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
    ifstream file("../data/students.txt");
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
    ofstream file("../data/students.txt");
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