// The run function implements the main user interface for the Skill Sharing Platform.
// It displays a menu and handles user input to navigate through various functionalities like user registration, messaging, and group management.
#include "../include/campus_connect.h"
#include <iostream>
using namespace std;

void campusconnect::run() {
    int choice;
    do {
        // Display the menu options to the user
        cout << "\n==== Skill Sharing Platform ====\n";
        cout << "1. Register User\n";
        cout << "2. List All Users\n";
        cout << "3. Show Users By Skill\n";
        cout << "4. Search Users (By Skill, Proficiency, Year)\n";
        cout << "5. Add Skill To User\n";
        cout << "6. Send Message\n";
        cout << "7. View Messages\n";
        cout << "8. View Chat History\n";
        cout << "9. Create Group\n";
        cout << "10. List Groups\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Handle the user's choice and call appropriate methods
        switch (choice) {
            case 1: users.registeruser(); break;  // Registers a new user
            case 2: users.listallusers(); break;  // Lists all registered users
            case 3: users.showbyskill(); break;  // Shows users filtered by skill
            case 4: {
                // Collects search parameters and searches for users by skill, proficiency, and year
                string skill;
                int proficiency, year;
                cout << "Enter skill to search (leave blank for no filter): ";
                cin.ignore();
                getline(cin, skill);
                cout << "Enter proficiency to search (1-10 or -1 for no filter): ";
                cin >> proficiency;
                cout << "Enter year to search (1-4 or -1 for no filter): ";
                cin >> year;
                users.searchusers(skill, proficiency, year);
                break;
            }
            case 5: {
                // Collects email and skill, then adds the new skill to the user
                string email, skill;
                cout << "Enter email: ";
                cin >> email;
                cout << "Enter new skill: ";
                cin >> skill;
                users.addskill(email, skill);
                break;
            }
            case 6: {
                // Collects sender and receiver emails and sends a message if both users exist
                string s, r;
                cout << "Enter sender email: ";
                cin >> s;
                cout << "Enter receiver email: ";
                cin >> r;
                if (users.getuserbyemail(s) && users.getuserbyemail(r))
                    messages.sendmessage(s, r);
                else
                    cout << "One or both users not found!\n";
                break;
            }
            case 7: {
                // Collects sender and receiver emails and displays the messages between them
                string s, r;
                cout << "Enter sender email: ";
                cin >> s;
                cout << "Enter receiver email: ";
                cin >> r;
                messages.viewmessages(s, r);
                break;
            }
            case 8: {
                // Collects sender and receiver emails and displays all chat history between them
                string s, r;
                cout << "Enter sender email: ";
                cin >> s;
                cout << "Enter receiver email: ";
                cin >> r;
                messages.viewallmessages(s, r);
                break;
            }
            case 9: groups.creategroup(); break;  // Creates a new group
            case 10: groups.listgroups(); break;  // Lists all groups
            case 0: cout << "Exiting...\n"; break;  // Exits the program
            default: cout << "Invalid choice!\n";  // Handles invalid choices
        }
    } while (choice != 0);  // Continues until the user selects "Exit"
}
