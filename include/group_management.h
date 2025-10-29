// This header file defines the groupmanager class which handles group creation and listing
#ifndef group_management_h
#define group_management_h

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure that holds information about a group, including its name and members
struct group {
    string name;               // Name of the group
    vector<string> members;    // List of members in the group
};

class groupmanager {
private:
    vector<group> groups;      // List of all groups

public:
    void creategroup();        // Creates a new group
    void listgroups();         // Lists all existing groups
};

#endif
