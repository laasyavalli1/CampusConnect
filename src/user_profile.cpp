#include "user_profile.h"
#include <iostream>
#include <algorithm>

User::User(const std::string& n, const std::string& e) : name(n), email(e) {}

std::string User::getName() const { return name; }
std::string User::getEmail() const { return email; }
const std::vector<std::string>& User::getSkills() const { return skills; }

void User::addSkill(const std::string& skill) {
    // avoid duplicates (case-insensitive optional; here exact match)
    if (std::find(skills.begin(), skills.end(), skill) == skills.end())
        skills.push_back(skill);
}

bool User::hasSkill(const std::string& skill) const {
    return std::find(skills.begin(), skills.end(), skill) != skills.end();
}

void User::displayProfile() const {
    std::cout << "Name: " << name << "\nEmail: " << email << "\nSkills:";
    if (skills.empty()) std::cout << " None";
    else {
        for (const auto &s : skills) std::cout << " " << s;
    }
    std::cout << "\n";
}
