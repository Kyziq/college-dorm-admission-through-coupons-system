#include "activity.h"

using namespace std;

// constructor
Activity::Activity(string id)
{
    this->id = id;
}

// method to get the activity ID
string Activity::getID()
{
    return this->id;
}