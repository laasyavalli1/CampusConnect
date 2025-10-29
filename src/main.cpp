#include "../include/user_profile.h"
#include "../include/messaging.h"
#include "../include/group_management.h"
#include <iostream>
using namespace std;

int main() {
    userdirectory directory;
    messagingsystem messenger;
    groupmanager groups;

    int choice;
    do {
        cout << "\n==== skill sharing platform ====\n";
        cout << "1. register user\n";
        cout << "2. list all users\n";
        cout << "3. show users by skill\n";
        cout << "4. send message\n";
        cout << "5. view messages\n";
        cout << "6. create group\n";
        cout << "7. list groups\n";
        cout << "0. exit\n";
        cout << "enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: directory.registeruser(); break;
            case 2: directory.listallusers(); break;
            case 3: directory.showbyskill(); break;
            case 4: {
                string s, r;
                cout << "enter sender email: ";
                cin >> s;
                cout << "enter receiver email: ";
                cin >> r;
                if (directory.getuserbyemail(s) && directory.getuserbyemail(r))
                    messenger.sendmessage(s, r);
                else
                    cout << " one or both users not found!\n";
                break;
            }
            case 5: {
                string s, r;
                cout << "enter sender email: ";
                cin >> s;
                cout << "enter receiver email: ";
                cin >> r;
                messenger.viewmessages(s, r);
                break;
            }
            case 6: groups.creategroup(); break;
            case 7: groups.listgroups(); break;
            case 0: cout << " exiting...\n"; break;
            default: cout << "invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}

