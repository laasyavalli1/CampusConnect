#include "campus_connect.h"
#include "group_management.h"
#include "messaging.h"
#include <iostream>
using namespace std;

int main() {
    CampusConnect cc;
    Messaging msg;
    Group devs("Developers");

    while (true) {
        cout << "\n====== Campus Connect Menu ======\n";
        cout << "1. Add User\n";
        cout << "2. Add Skill to User\n";
        cout << "3. List Users\n";
        cout << "4. Send Message\n";
        cout << "5. View All Messages\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;
        cin.ignore(); // clear newline from buffer

        if (choice == 1) {
            string name, email;
            cout << "Enter user name: ";
            getline(cin, name);
            cout << "Enter user email: ";
            getline(cin, email);

            if (cc.createUser(name, email))
                cout << "✅ User created successfully!\n";
            else
                cout << "⚠️ User already exists.\n";
        }

        else if (choice == 2) {
            string email, skill;
            cout << "Enter user email: ";
            getline(cin, email);
            cout << "Enter skill to add: ";
            getline(cin, skill);

            if (cc.addSkill(email, skill))
                cout << "✅ Skill added!\n";
            else
                cout << "⚠️ Could not add skill (user not found).\n";
        }

        else if (choice == 3) {
            cout << "\n--- User List ---\n";
            auto users = cc.listUsers();
            for (const auto& email : users) {
                User* u = cc.getUser(email);
                if (u) u->displayProfile();
                cout << "----------------\n";
            }
        }

        else if (choice == 4) {
            string sender, receiver, content;
            cout << "Sender email: ";
            getline(cin, sender);
            cout << "Receiver email: ";
            getline(cin, receiver);
            cout << "Message: ";
            getline(cin, content);

            msg.sendMessage({sender, receiver, content});
            cout << "✅ Message sent!\n";
        }

        else if (choice == 5) {
            cout << "\n--- All Messages ---\n";
            msg.showAllMessages();
        }

        else if (choice == 6) {
            cout << "👋 Exiting program. Goodbye!\n";
            break;
        }

        else {
            cout << "❌ Invalid choice.\n";
        }
    }

    return 0;
}
