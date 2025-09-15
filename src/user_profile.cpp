#include "user_profile.h"
#include <iostream>
using namespace std;

// Add a new user profile
void UserManager::addUser(string username, string branch, string skills) {
    if (users.find(username) != users.end()) {
        cout << "User already exists!\n";
        return;
    }

    UserProfile newUser = {username, branch, skills};
    users[username] = newUser;
    cout << "User " << username << " added successfully.\n";
}

// Display all users
void UserManager::displayUsers() {
    cout << "\n--- Registered Users ---\n";
    for (auto &entry : users) {
        cout << "Username: " << entry.second.username
             << " | Branch: " << entry.second.branch
             << " | Skills: " << entry.second.skills << endl;
    }
}

// Check if user exists
bool UserManager::userExists(string username) {
    return users.find(username) != users.end();
}

