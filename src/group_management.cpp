// The groupmanager class handles the creation and listing of groups within the platform.
#include "../include/group_management.h"
#include <iostream>
using namespace std;

// Creates a new group by asking the user for the group name and members' emails
void groupmanager::creategroup() {
    cin.ignore();  
    group g;       
    cout << "Enter group name: ";
    getline(cin, g.name);  

    int n;
    cout << "Enter number of members: ";
    cin >> n;  // Get the number of members
    cin.ignore();  

    // Collects the emails of the group members
    for (int i = 0; i < n; i++) {
        string email;
        cout << "Enter member " << i + 1 << " email: ";
        getline(cin, email);  // Get the email for each member
        g.members.push_back(email);  // Add the member to the group
    }

    groups.push_back(g);  // Add the new group to the groups list
    cout << "Group created successfully!\n";  
}

// Lists all the groups and their members
void groupmanager::listgroups() {
    cout << "\nGroups:\n";
    // Iterates through all groups and displays their name and members
    for (auto& g : groups) {
        cout << "- " << g.name << " [ ";
        for (auto& m : g.members) cout << m << " ";  // List each member of the group
        cout << "]\n";
    }
}
