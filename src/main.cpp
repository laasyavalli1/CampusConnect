// This is the main function that runs the skill sharing platform. It presents a menu to the user for different functionalities such as user registration, messaging, and group management.

#include "../include/user_profile.h"
#include "../include/messaging.h"
#include "../include/group_management.h"
#include <iostream>
using namespace std;

int main() {
    userdirectory directory;  // Object to manage user directory
    messagingsystem messenger; // Object to manage messaging
    groupmanager groups;      // Object to manage groups

    int choice;
    do {
        // Displaying the menu of options
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

        // Handle user choice
        switch (choice) {
            case 1: directory.registeruser(); break;  // Register a new user
            case 2: directory.listallusers(); break;  // List all users
            case 3: directory.showbyskill(); break;   // Show users based on skill
            case 4: {  
                string s, r;
                cout << "enter sender email: ";
                cin >> s;
                cout << "enter receiver email: ";
                cin >> r;
                if (directory.getuserbyemail(s) && directory.getuserbyemail(r))
                    messenger.sendmessage(s, r);  // Send message if both users exist
                else
                    cout << " one or both users not found!\n";
                break;
            }
            case 5: {  // View messages
                string s, r;
                cout << "enter sender email: ";
                cin >> s;
                cout << "enter receiver email: ";
                cin >> r;
                messenger.viewmessages(s, r);  // View messages between sender and receiver
                break;
            }
            case 6: groups.creategroup(); break;  // Create a new group
            case 7: groups.listgroups(); break;  // List all groups
            case 0: cout << " exiting...\n"; break;  // Exit the system
            default: cout << "invalid choice!\n";  // Handle invalid menu choices
        }
    } while (choice != 0);  // Continue until user selects exit

    return 0;  
}
