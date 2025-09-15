#ifndef GROUP_MANAGEMENT_H
#define GROUP_MANAGEMENT_H

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class GroupManager {
private:
    unordered_map<string, vector<string>> groups; // group name → list of usernames

public:
    void createGroup(string groupName);
    void joinGroup(string groupName, string username);
    void displayGroups();
};

#endif

