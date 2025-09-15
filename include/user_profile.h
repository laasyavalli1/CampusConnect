#ifndef USER_PROFILE_H
#define USER_PROFILE_H

#include <string>
#include <unordered_map>
using namespace std;

// Structure to hold user information
struct UserProfile {
    string username;
    string branch;
    string skills;
};

// User Manager for adding and managing profiles
class UserManager {
private:
    unordered_map<string, UserProfile> users; // key = username

public:
    void addUser(string username, string branch, string skills);
    void displayUsers();
    bool userExists(string username);
};

#endif

