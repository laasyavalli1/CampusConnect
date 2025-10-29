#ifndef group_management_h
#define group_management_h

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct group {
    string name;
    vector<string> members;
};

class groupmanager {
private:
    vector<group> groups;

public:
    void creategroup();
    void listgroups();
};

#endif
