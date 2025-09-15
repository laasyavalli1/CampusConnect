#include "group_management.h"
#include <iostream>
using namespace std;

// Create a new group
void GroupManager::createGroup(string groupName) {
    if (groups.find(groupName) != groups.end()) {
        cout << "Group already exists!\n";
        return;
    }
    groups[groupName] = {};
    cout << "Group '" << groupName << "' created successfully.\n";
}

// Add user to a group
void GroupManager::joinGroup(string groupName, string username) {
    if (groups.find(groupName) == groups.end()) {
        cout << "Group does not exist!\n";
        return;
    }
    groups[groupName].push_back(username);
    cout << username << " joined group " << groupName << ".\n";
}

// Display all groups and members
void GroupManager::displayGroups() {
    cout << "\n--- Groups ---\n";
    for (auto &entry : groups) {
        cout << "Group: " << entry.first << "\nMembers: ";
        for (auto &member : entry.second) {
            cout << member << " ";
        }
        cout << endl;
    }
}

