#include "dormAdmission.h"

using namespace std;

// constructor takes pointer to a Student object
DormAdmission::DormAdmission(Student *student)
{
    this->student = student;
}

// method to check whether the student is eligible for dorm admission
bool DormAdmission::checkEligibility()
{
    // for example, let's say a student is eligible if they have 10 or more coupons
    return this->student->getCoupon() >= 10;
}