#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class Student
{
private:
    string id;  // student ID
    int coupon; // current coupon count

public:
    // Constructor
    Student(string id);

    // Getter
    string getID();  // method to get the student's ID
    int getCoupon(); // method to get the student's coupon count

    // Setter
    void setCoupon(int coupon); // method to set the student's coupon count
};

#endif