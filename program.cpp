#include <iostream>
#include <fstream>

const string STUDENT_INFO_FILE = "student_infot.txt";
const int MAX_STUDENT = 10;
const int MAX_ACTIVITIES = 10;
const int size = 2;

using namespace std;

// Structure to store student information
struct Student
{
    string studentID;
    string studentName;
    string activityCode;
    int couponCount;
};

// Structure to store participation information
struct ParticipantInfo
{
    string studentID;
    string activityID;
};

// Structure to store activity information
struct Activity
{
    string activityID;
    string activityName;
};

// Function to calculate coupon count
int calculateCouponCount(int numActivities)
{
    cout << "Enter the number of activities";
    cin >> numActivities;

    int couponCount = numActivities;
    return couponCount;
}

// Function to register student information
void registerStudent(Student students[], ParticipantInfo participants[][MAX_ACTIVITIES], int &numStudents)
{
    cout << "Enter the number of students to register : ";
    cin >> numStudents;

    for (int i = 0; i < numStudents; i++)
    {
        cout << "Student ID: ";
        cin >> students[i].studentID;

        cout << "Student Name: ";
        cin >> students[i].studentName;

        cout << "Activity code: ";
        cin >> students[i].activityCode;

        int numActivities;
        cout << "Enter the number of activities for Student ID " << students[i].studentID << ": ";
        cin >> numActivities;

        // Input the activity IDs for each student
        for (int j = 0; j < numActivities; j++)
        {
            cout << "Activity ID for Activity " << j + 1 << ": ";
            cin >> participants[i][j].activityID;
        }

        // calculate coupon count based on user input
        students[i].couponCount = calculateCouponCount(numActivities);
    }
    writeStudentInfo(students, numStudents);
}

// Function to write student information to a file
void writeStudentInfo(const Student *students, int numStudent)
{
}

// Function to read student information from a file
void readStudentInfo(const Student *students, int numStudent)
{
}

int main()
{
    Student students[MAX_STUDENT];
    ParticipantInfo participants[MAX_STUDENT][MAX_ACTIVITIES];
    Activity activityInfo[MAX_ACTIVITIES];

    int numStudents = 0;
    registerStudent(students, participants, numStudents);

    system("pause");
    return 0;
}
