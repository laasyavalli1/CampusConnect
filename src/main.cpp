// The main function implements the Skill Sharing Platform's user interface, handling user interaction for managing users, messaging, and groups.
#include "../include/user_profile.h"
#include "../include/messaging.h"
#include "../include/group_management.h"
#include <iostream>
using namespace std;

int main() {
    userdirectory directory;  // Manages user profiles
    messagingsystem messenger;  // Handles messaging functionality
    groupmanager groups;  // Manages groups

    int choice;
    do {
        // Displays the menu options to the user
        cout << "\n==== Skill Sharing Platform ====\n";
        cout << "1. Register user\n";
        cout << "2. List all users\n";
        cout << "3. Show users by skill\n";
        cout << "4. Search users (by skill, proficiency, year)\n";  // Updated to mention proficiency
        cout << "5. Add skill to user\n";
        cout << "6. Send message\n";
        cout << "7. View messages\n";
        cout << "8. View chat history\n";
        cout << "9. Create group\n";
        cout << "10. List groups\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Handles the user's choice and calls the corresponding function
        switch (choice) {
            case 1: directory.registeruser(); break;  // Registers a new user
            case 2: directory.listallusers(); break;  // Lists all registered users
            case 3: directory.showbyskill(); break;  // Shows users filtered by skill
            case 4: {
                // Collects search parameters and searches for users based on skill, proficiency, and year
                string skill;
                int year, proficiency;
                cout << "Enter skill to search (leave blank for no filter): ";
                cin.ignore();
                getline(cin, skill);
                cout << "Enter minimum proficiency (1-10 or -1 for no filter): ";  // Added
                cin >> proficiency;
                cout << "Enter year to search (1-4 or -1 for no filter): ";
                cin >> year;
                directory.searchusers(skill, proficiency, year);  // Updated to include proficiency
                break;
            }
            case 5: {
                // Collects user email and skill to add the new skill to the user profile
                string email, skill;
                cout << "Enter email: ";
                cin >> email;
                cout << "Enter new skill: ";
                cin >> skill;
                directory.addskill(email, skill);
                break;
            }
            case 6: {
                // Collects sender and receiver emails to send a message
                string s, r;
                cout << "Enter sender email: ";
                cin >> s;
                cout << "Enter receiver email: ";
                cin >> r;
                if (directory.getuserbyemail(s) && directory.getuserbyemail(r))
                    messenger.sendmessage(s, r);  // Sends the message if both users exist
                else
                    cout << "One or both users not found!\n";  // Error message if users not found
                break;
            }
            case 7: {
                // Collects sender and receiver emails to view their messages
                string s, r;
                cout << "Enter sender email: ";
                cin >> s;
                cout << "Enter receiver email: ";
                cin >> r;
                messenger.viewmessages(s, r);  // Displays the messages between the two users
                break;
            }
            case 8: {
                // Collects sender and receiver emails to view their chat history
                string s, r;
                cout << "Enter sender email: ";
                cin >> s;
                cout << "Enter receiver email: ";
                cin >> r;
                messenger.viewallmessages(s, r);  // Displays the entire chat history between the two users
                break;
            }
            case 9: groups.creategroup(); break;  // Creates a new group
            case 10: groups.listgroups(); break;  // Lists all groups
            case 0: cout << "Exiting...\n"; break;  // Exits the program
            default: cout << "Invalid choice!\n";  // Handles invalid choices
        }
    } while (choice != 0);  // Continues until the user selects "Exit"

    return 0;
}
