// This file implements the `groupmanager` class, which manages group creation and listing. 
// It allows users to create new groups by specifying a name and members, as well as listing all groups and their members.

#include "../include/group_management.h"
#include <iostream>
using namespace std;

void groupmanager::creategroup() {
    cin.ignore();  
    group g;
    cout << "enter group name: ";
    getline(cin, g.name);  
    int n;
    cout << "enter number of members: ";
    cin >> n;  // Get number of members in the group
    cin.ignore();  

    // Loop to get member emails and add them to the group
    for (int i = 0; i < n; i++) {
        string email;
        cout << "enter member " << i + 1 << " email: ";
        getline(cin, email);  // Get each member's email
        g.members.push_back(email);  // Add email to the group's member list
    }
    
    groups.push_back(g);  // Add the new group to the list of groups
    cout << " group created successfully!\n";  
}

void groupmanager::listgroups() {
    cout << "\ngroups:\n";
    // Loop through and list each group and its members
    for (auto& g : groups) {
        cout << "- " << g.name << " [ ";  // Print group name
        for (auto& m : g.members) cout << m << " ";  // Print each member's email
        cout << "]\n";  
    }
}
