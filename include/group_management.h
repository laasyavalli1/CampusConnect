// This header file defines a `group` structure with a name and a list of members, 
// and a `groupmanager` class that allows for creating and listing groups.

#ifndef group_management_h
#define group_management_h

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct group {
    string name;           // Name of the group
    vector<string> members; // List of members in the group
};

class groupmanager {
private:
    vector<group> groups; // Container to hold all the groups

public:
    void creategroup();    // Function to create a new group
    void listgroups();     // Function to list all the groups
};

#endif
