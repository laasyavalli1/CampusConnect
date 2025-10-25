
#include "navigation.h"
#include "user_profile.h"
#include "group_management.h"
#include "messaging.h"
#include <iostream>
#include <vector>
using namespace std;

void startSkillSharingMenu() {
    vector<User> users;
    vector<Group> groups;
    vector<Message> chat;

    int choice;
    do {
        cout << "\n=== Skill Sharing Menu ===\n";
        cout << "1. Create User\n";
        cout << "2. Create Group\n";
        cout << "3. Join Group\n";
        cout << "4. Post Message\n";
        cout << "5. View Messages\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            int id; string name, branch, skill;
            cout << "Enter id, name, branch, skill: ";
            cin >> id >> name >> branch >> skill;
            users.push_back(createUser(id, name, branch, skill));
        } 
        else if (choice == 2) {
            string gname;
            cout << "Enter group name: ";
            cin >> gname;
            groups.push_back(createGroup(gname));
        } 
        else if (choice == 3) {
            if (groups.empty() || users.empty()) {
                cout << "Create users and groups first.\n";
                continue;
            }
            int uid, gid;
            cout << "Enter user index and group index: ";
            cin >> uid >> gid;
            if (uid < users.size() && gid < groups.size())
                addUserToGroup(groups[gid], users[uid]);
            else
                cout << "Invalid indices!\n";
        } 
        else if (choice == 4) {
            if (users.empty()) {
                cout << "No users available.\n";
                continue;
            }
            int uid;
            cout << "Enter user index to post: ";
            cin >> uid;
            cin.ignore();
            string msg;
            cout << "Enter message: ";
            getline(cin, msg);
            if (uid < users.size())
                postMessage(chat, users[uid], msg);
        } 
        else if (choice == 5) {
            viewMessages(chat);
        }
    } while (choice != 6);
}
