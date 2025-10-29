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
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string email;
        cout << "enter member " << i + 1 << " email: ";
        getline(cin, email);
        g.members.push_back(email);
    }
    groups.push_back(g);
    cout << " group created successfully!\n";
}

void groupmanager::listgroups() {
    cout << "\ngroups:\n";
    for (auto& g : groups) {
        cout << "- " << g.name << " [ ";
        for (auto& m : g.members) cout << m << " ";
        cout << "]\n";
    }
}
