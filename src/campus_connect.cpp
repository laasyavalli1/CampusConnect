#include "../include/campus_connect.h"
#include <iostream>
using namespace std;

void campusconnect::run() {
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
            case 1: users.registeruser(); break;
            case 2: users.listallusers(); break;
            case 3: users.showbyskill(); break;
            case 4: {
                string s, r;
                cout << "enter sender email: ";
                cin >> s;
                cout << "enter receiver email: ";
                cin >> r;
                if (users.getuserbyemail(s) && users.getuserbyemail(r))
                    messages.sendmessage(s, r);
                else
                    cout << "one or both users not found!\n";
                break;
            }
            case 5: {
                string s, r;
                cout << "enter sender email: ";
                cin >> s;
                cout << "enter receiver email: ";
                cin >> r;
                messages.viewmessages(s, r);
                break;
            }
            case 6: groups.creategroup(); break;
            case 7: groups.listgroups(); break;
            case 0: cout << " exiting...\n"; break;
            default: cout << "invalid choice!\n";
        }
    } while (choice != 0);
}
