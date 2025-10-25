#include "campus_connect.h"
#include <iostream>

bool CampusConnect::createUser(const std::string &name, const std::string &email) {
    if (users.find(email) != users.end())
        return false;
    users[email] = {name, email, ""};
    return true;
}

bool CampusConnect::addSkill(const std::string &email, const std::string &skill) {
    auto it = users.find(email);
    if (it == users.end()) return false;
    it->second.skill = skill;
    return true;
}

std::vector<std::string> CampusConnect::listUsers() const {
    std::vector<std::string> list;
    for (const auto &p : users)
        list.push_back(p.first);
    return list;
}

User* CampusConnect::getUser(const std::string &email) {
    auto it = users.find(email);
    return (it != users.end()) ? &it->second : nullptr;
}

void User::displayProfile() const {
    std::cout << "Name: " << name << "\nEmail: " << email << "\nSkill: " << skill << "\n";
}
