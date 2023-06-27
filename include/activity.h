#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <string>

using namespace std;

class Activity
{
private:
    string id; // activity ID

public:
    // Constructor
    Activity(string id);

    // Getter
    string getID();
};

#endif