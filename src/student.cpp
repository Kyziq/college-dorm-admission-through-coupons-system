#include "student.h"

using namespace std;

// constructor
Student::Student(string id)
{
    this->id = id;
    this->coupon = 0; // initialize coupon count to 0
}

// method to get the student's ID
string Student::getID()
{
    return this->id;
}

// method to get the student's coupon count
int Student::getCoupon()
{
    return this->coupon;
}

// method to set/increment the student's coupon count
void Student::setCoupon(int coupon)
{
    this->coupon = coupon;
}