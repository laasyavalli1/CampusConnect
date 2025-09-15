#include "campus_connect.h"
#include "navigation.h"
#include <iostream>
#include <string>

int main() {
    CampusConnect app;
    Navigation nav;
    int choice = -1;
    while (choice != 0) {
        nav.showMenu();
        std::cout << "Enter choice: ";
        if (!(std::cin >> choice)) break;
        if (choice == 1) {
            std::string name, email;
            std::cout << "Name: ";
            std::cin >> std::ws;
            std::getline(std::cin, name);
            std::cout << "Email: ";
            std::cin >> email;
            if (app.createUser(name, email)) std::cout << "User created.\n";
            else std::cout << "User already exists.\n";
        } else if (choice == 2) {
            auto users = app.listUsers();
            std::cout << "Users:\n";
            if (users.empty()) std::cout << " (none)\n";
            for (const auto &e : users) {
                auto u = app.getUser(e);
                if (u) u->displayProfile();
            }
        } else if (choice == 3) {
            std::string email, skill;
            std::cout << "User email: ";
            std::cin >> email;
            std::cout << "Skill: ";
            std::cin >> skill;
            if (app.addSkillToUser(email, skill)) std::cout << "Skill added.\n";
            else std::cout << "User not found.\n";
        } else if (choice == 4) {
            std::string skill;
            std::cout << "Skill to search: ";
            std::cin >> skill;
            auto res = app.findUsersWithSkill(skill);
            std::cout << "Found " << res.size() << " user(s):\n";
            for (const auto &e : res) {
                auto u = app.getUser(e);
                if (u) std::cout << " - " << u->getName() << " (" << e << ")\n";
            }
        } else if (choice == 5) {
            std::string g;
            std::cout << "Group name: ";
            std::cin >> std::ws;
            std::getline(std::cin, g);
            if (app.createGroup(g)) std::cout << "Group created.\n";
            else std::cout << "Group already exists.\n";
        } else if (choice == 6) {
            std::string g, email;
            std::cout << "Group name: ";
            std::cin >> std::ws;
            std::getline(std::cin, g);
            std::cout << "User email: ";
            std::cin >> email;
            if (app.addUserToGroup(g, email)) std::cout << "Added to group.\n";
            else std::cout << "Group or user not found.\n";
        } else if (choice == 7) {
            auto groups = app.listGroups();
            std::cout << "Groups:\n";
            if (groups.empty()) std::cout << " (none)\n";
            for (const auto &g : groups) {
                std::cout << " - " << g << "\n";
            }
        } else if (choice == 8) {
            std::string from, to, content;
            std::cout << "From (email): ";
            std::cin >> from;
            std::cout << "To (email): ";
            std::cin >> to;
            std::cout << "Message: ";
            std::cin.ignore();
            std::getline(std::cin, content);
            app.sendMessage(from, to, content);
            std::cout << "Message queued.\n";
        } else if (choice == 9) {
            app.showAllMessages();
        } else if (choice == 0) {
            std::cout << "Goodbye.\n";
        } else {
            std::cout << "Invalid choice.\n";
        }
    }
    return 0;
}

