#ifndef DORMADMISSION_H
#define DORMADMISSION_H

#include "student.h"

using namespace std;

class DormAdmission
{
private:
    Student *student; // pointer to the student to check for dorm admission eligibility

public:
    // Constructor
    DormAdmission(Student *student); // takes pointer to a Student object

    // Function
    bool checkEligibility(); // method to check whether the student is eligible for dorm admission
};

#endif