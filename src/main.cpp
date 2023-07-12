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

/***** Struct *****/

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

// Global constants and arrays to hold students and activities
const int MAX_ACTIVITIES = 10;
const int MAX_STUDENTS = 50;

Student students[MAX_STUDENTS];
Activity activities[MAX_ACTIVITIES];
string participations[MAX_STUDENTS][MAX_ACTIVITIES];

// Global variables for the current number of students and activities
int numStudents = 0;
int numActivities = 0;
int numParticipations[MAX_STUDENTS] = {0};

// Global constants for the paths to the data files
const string STUDENTS_FILE = "../data/students.txt";
const string ACTIVITIES_FILE = "../data/activities.txt";
const string PARTICIPATIONS_FILE = "../data/participations.txt";

/***** Helper Functions *****/

/** Helper Functions - Data Loading **/
// Function to load students data from the file
void loadStudents()
{
    ifstream inputFile(STUDENTS_FILE);
    // Exception handling: throw an error if the file cannot be opened
    if (!inputFile)
    {
        throw runtime_error("Unable to open students file for reading.");
    }

    string line;
    while (getline(inputFile, line)) // reading the file line by line
    {
        stringstream ss(line);
        string id, name;
        int coupons;

        getline(ss, id, ',');
        getline(ss, name, ',');
        ss >> coupons;

        students[numStudents] = {id, name, coupons};
        numStudents++;
    }
    inputFile.close();
}

// Function to load activites data from the file
void loadActivities()
{
    ifstream inputFile(ACTIVITIES_FILE);
    // Exception handling: throw an error if the file cannot be opened
    if (!inputFile)
    {
        throw runtime_error("Unable to open activities file for reading.");
    }

    numActivities = 0;
    string line;
    while (getline(inputFile, line)) // reading the file line by line
    {
        stringstream ss(line);

        getline(ss, activities[numActivities].id, ',');
        getline(ss, activities[numActivities].name, ',');
        numActivities++;
    }
    inputFile.close();
}

// Function to load participation data from the file
void loadParticipations()
{
    ifstream inputFile(PARTICIPATIONS_FILE);
    // Exception handling: throw an error if the file cannot be opened
    if (!inputFile)
    {
        throw runtime_error("Unable to open participation file for reading.");
    }

    numStudents = 0; // Reset the number of students
    string line;
    while (getline(inputFile, line)) // reading the file line by line
    {
        stringstream ss(line);
        string studentId;
        string activityId;

        getline(ss, studentId, ',');
        int i = 0;
        while (getline(ss, activityId, ','))
        {
            if (i >= MAX_ACTIVITIES)
            {
                cerr << "Maximum number of activities reached for student " << studentId << ". Ignoring additional activities.\n";
                break;
            }
            participations[numStudents][i] = activityId;
            i++;
        }
        numParticipations[numStudents] = i; // Update the number of participations for the student
        numStudents++;
        if (numStudents >= MAX_STUDENTS)
        {
            cerr << "Maximum number of students reached. Ignoring additional students.\n";
            break;
        }
    }
    inputFile.close();
}

/** Helper Functions - Data Saving and Searching **/
// Function to save students data to the file
void saveStudents()
{
    ofstream outputFile(STUDENTS_FILE);
    // Exception handling: throw an error if the file cannot be opened
    if (!outputFile)
    {
        throw runtime_error("Unable to open students file for writing.");
    }
    for (int i = 0; i < numStudents; i++)
    {
        outputFile << students[i].id << ',' << students[i].name << ',' << students[i].coupons << '\n';
    }
    outputFile.close();
}

// Function to save participations data to the file
void saveParticipations()
{
    ofstream outputFile(PARTICIPATIONS_FILE);
    if (!outputFile)
    {
        throw runtime_error("Unable to open participations file for writing.");
    }
    for (int i = 0; i < numStudents; i++)
    {
        outputFile << students[i].id;
        for (int j = 0; j < numParticipations[i]; j++)
        {
            outputFile << ',' << participations[i][j];
        }
        outputFile << '\n';
    }
    outputFile.close();
}

// Find a student by their id
Student *findStudentById(const string &id)
{
    for (int i = 0; i < numStudents; i++)
    {
        if (students[i].id == id)
            return &students[i]; // return the student
    }
    // If student is not found, throw an exception
    throw runtime_error("Student not found!");
}

// Find an activity by their id
Activity *findActivityById(const string &id)
{
    for (int i = 0; i < numActivities; i++)
    {
        if (activities[i].id == id)
            return &activities[i]; // return the activity
    }
    // If activity is not found, throw an exception
    throw runtime_error("Activity not found!");
}

/** Display Functions **/
// Print the details of all students
void displaySingleStudent()
{
    string stuId, actId;
    cout << "Enter student ID: ";
    cin >> stuId;

    // Find the student in the students array
    const Student *student = findStudentById(stuId);
    if (student)
    {
        cout << "ID: " << student->id << ", Name: " << student->name << ", Coupons: " << student->coupons << "\n\n";
    }
    else
    {
        cerr << "Student not found!\n";
    }
}
void displayAllStudents()
{
    cout << "Registered Students:\n";
    for (int i = 0; i < numStudents; i++)
    {
        const Student &student = students[i];
        cout << "ID: " << student.id << ", Name: " << student.name << ", Coupons: " << student.coupons << "\n";
    }
    cout << endl;
}

// Print the details of all activities
void displayAllActivities()
{
    cout << "Registered Activities:\n";
    for (int i = 0; i < numActivities; i++)
    {
        cout << "ID: " << activities[i].id << ", Name: " << activities[i].name << '\n';
    }
    cout << endl;
}

// Function to display student activities
void displayStudentActivities(const string &id)
{
    // Find the student in the students array
    int studentIndex = -1;
    for (int i = 0; i < numStudents; i++)
    {
        if (students[i].id == id)
        {
            studentIndex = i;
            break;
        }
    }

    if (studentIndex != -1) // If the student was found
    {
        cout << "Student ID: " << students[studentIndex].id << ", Name: " << students[studentIndex].name << '\n';
        cout << "Activities Joined:\n";

        // Iterate over the student's participations
        for (int i = 0; i < numParticipations[studentIndex]; i++)
        {
            // Find the activity in the activities array
            Activity *activity = findActivityById(participations[studentIndex][i]);
            if (activity) // If the activity was found
            {
                cout << "ID: " << activity->id << ", Name: " << activity->name << '\n';
            }
            else // If the activity was not found
            {
                // If activity is not found, throw an exception
                throw runtime_error("Activity not found!");
            }
        }
        cout << '\n';
    }
    else
    {
        // If student is not found, throw an exception
        throw runtime_error("Student not found!");
    }
}

/** etc Functions **/
bool studentExists(const string &stuId)
{
    for (int i = 0; i < numStudents; i++)
    {
        if (students[i].id == stuId)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    // Initialization phase: Load students, activities, and participations data
    try
    {
        loadStudents();
        loadActivities();
        loadParticipations();
    }
    catch (const runtime_error &e)
    {
        // If any file operation fails, print error message and exit the program.
        cerr << "Error while loading data: " << e.what() << '\n';
        return -1;
    }

    // Run the program until the user exits
    while (true)
    {
        // Display the main menu and get the user's choice
        cout << "Welcome to the College Dorm Admission through Coupons (CDAC) System!\n"
             << "1 - Register a new student\n"
             << "2 - Add a coupon to a student\n"
             << "3 - Check a student's dorm eligibility\n"
             << "4 - Display student(s)\n"
             << "5 - Display all activities\n"
             << "6 - Display a student's activities\n"
             << "7 - Exit the program\n"
             << "Enter your choice: ";
        int choice;
        cin >> choice;

        try
        {
            if (choice == 1) // Register a new student
            {
                // Get the new student's information from the user
                string stuId, stuName;
                cout << "Enter the new student's ID: ";
                cin >> stuId;

                if (!studentExists(stuId)) // If the student was not found, continue
                {
                    cin.ignore(); // Clear the newline character from the input buffer
                    cout << "Enter the new student's name: ";
                    getline(cin, stuName);

                    // Add the new student to the students array and save the updated students array to the file
                    students[numStudents] = {stuId, stuName, 0};
                    numStudents++;
                    saveStudents();
                    cout << "The student has been registered!\n\n";
                }
                else
                {
                    cerr << "Student not found!\n\n";
                }
            }
            else if (choice == 2) // Add coupon to student
            {
                string stuId, actId;
                cout << "Enter student ID: ";
                cin >> stuId;

                // Find the student in the students array
                int studentIndex = -1;
                for (int i = 0; i < numStudents; i++)
                {
                    if (students[i].id == stuId)
                    {
                        studentIndex = i;
                        break;
                    }
                }

                if (studentIndex != -1) // If the student was found
                {
                    // Display all activities and get the activity ID from the user
                    displayAllActivities();
                    cout << "Enter the activity ID that the student participated in: ";
                    cin >> actId;

                    // Find the activity in the activities array
                    Activity *activity = findActivityById(actId);
                    if (activity) // If the activity was found
                    {
                        // Check if the student has already participated in this activity
                        bool alreadyParticipated = false;
                        for (int i = 0; i < numParticipations[studentIndex]; i++)
                        {
                            if (participations[studentIndex][i] == actId)
                            {
                                alreadyParticipated = true;
                                break;
                            }
                        }

                        if (alreadyParticipated)
                        {
                            cerr << "The student has already participated in this activity.\n\n";
                        }
                        else
                        {
                            // Add a coupon to the student
                            students[studentIndex].coupons++;

                            // Add the activity to the student's participations
                            participations[studentIndex][numParticipations[studentIndex]] = actId;
                            numParticipations[studentIndex]++;

                            // Save the updated students and participations data to the files
                            saveStudents();
                            saveParticipations();

                            cout << "A coupon has been added to the student, and the activity has been added to the student's participations.\n\n";
                        }
                    }
                    else // If the activity was not found
                    {
                        cerr << "Activity not found!\n\n";
                    }
                }
                else
                {
                    cerr << "Student not found!\n\n";
                }
            }
            else if (choice == 3) // Check student dorm status
            {
                string stuId;
                cout << "Enter student ID: ";
                cin >> stuId;

                if (!studentExists(stuId)) // If the student was not found, continue
                {
                    // Find the student in the students array
                    Student *student = findStudentById(stuId);
                    if (student->coupons >= 10)
                    {
                        cout << "Student is eligible for dorm admission!\n\n";
                    }
                    else
                    {
                        cout << "Student is not eligible for dorm admission.\n\n";
                    }
                }
                else
                {
                    cerr << "Student not found!\n\n";
                }
            }

            else if (choice == 4) // Display all students
            {
                int choice4;
                cout << "Do you want to display a student (Input 1) or all students (Input 2)? : ";
                cin >> choice4;
                if (choice4 == 1)
                {
                    displaySingleStudent();
                }
                else if (choice4 == 2)
                {
                    displayAllStudents();
                }
                else
                {
                    cerr << "Invalid choice. Please enter from 1 to 2!\n";
                }
            }
            else if (choice == 5) // Display all activities
            {
                displayAllActivities();
            }
            else if (choice == 6) // Display student activities
            {
                string id;
                cout << "Enter student ID: ";
                cin >> id;
                displayStudentActivities(id);
            }
            else if (choice == 7) // Exit
            {
                cout << "Exiting the program.\n";
                break;
            }
            else
            {
                cerr << "Invalid choice. Please enter from 1 to 6!\n";
            }
        }
        catch (const runtime_error &e)
        {
            cerr << "An error occurred: " << e.what() << "\n\n";
        }
    }
    return 0;
}