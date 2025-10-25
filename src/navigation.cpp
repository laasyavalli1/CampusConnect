// navigation.cpp
#include "campus_connect.h"
#include "group_management.h"
#include "messaging.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Example function to start a simple navigation menu
void startSkillSharingMenu() {
    CampusConnect cc;
    Messaging chat;
    vector<Group> groups;

    while (true) {
        cout << "\n====== Skill Sharing Menu ======\n";
        cout << "1. Add User\n";
        cout << "2. Add Skill to User\n";
        cout << "3. List Users\n";
        cout << "4. Create Group\n";
        cout << "5. Add User to Group\n";
        cout << "6. Send Message\n";
        cout << "7. View Messages\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;
        cin.ignore(); // remove leftover newline

        if (choice == 1) {
            string name, email;
            cout << "Enter name: ";
            getline(cin, name);
            cout << "Enter email: ";
            getline(cin, email);

            if (cc.createUser(name, email))
                cout << "User created successfully.\n";
            else
                cout << "User already exists.\n";
        }
        else if (choice == 2) {
            string email, skill;
            cout << "Enter user email: ";
            getline(cin, email);
            cout << "Enter skill to add: ";
            getline(cin, skill);

            if (cc.addSkill(email, skill))
                cout << "Skill added successfully.\n";
            else
                cout << "User not found.\n";
        }
        else if (choice == 3) {
            auto users = cc.listUsers();
            cout << "--- Users ---\n";
            for (const auto &email : users) {
                User* u = cc.getUser(email);
                if (u) u->displayProfile();
                cout << "--------------\n";
            }
        }
        else if (choice == 4) {
            string gname;
            cout << "Enter group name: ";
            getline(cin, gname);
            groups.emplace_back(gname);
            cout << "Group created successfully.\n";
        }
        else if (choice == 5) {
            if (groups.empty()) {
                cout << "No groups available. Create a group first.\n";
                continue;
            }

            cout << "Available groups:\n";
            for (int i = 0; i < groups.size(); ++i)
                cout << i << ": " << groups[i].getName() << "\n";

            int gid;
            cout << "Enter group ID: ";
            cin >> gid;
            cin.ignore();

            string email;
            cout << "Enter user email to add: ";
            getline(cin, email);

            User* u = cc.getUser(email);
            if (u) {
                groups[gid].addMember(email);
                cout << "User added to group.\n";
            } else {
                cout << "User not found.\n";
            }
        }
        else if (choice == 6) {
            string sender, receiver, msgContent;
            cout << "Sender email: ";
            getline(cin, sender);
            cout << "Receiver email: ";
            getline(cin, receiver);
            cout << "Message: ";
            getline(cin, msgContent);

            chat.sendMessage({sender, receiver, msgContent});
            cout << "Message sent.\n";
        }
        else if (choice == 7) {
            auto messages = chat.getAllMessages();
            cout << "--- Messages ---\n";
            for (const auto &m : messages)
                cout << m.senderEmail << " -> " << m.receiverEmail << ": " << m.content << "\n";
        }
        else if (choice == 8) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }
}
