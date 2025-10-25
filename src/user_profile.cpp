#include "user_profile.h"
#include <algorithm>
#include <iostream>

// Constructor
User::User(const std::string& name, const std::string& email)
    : name_(name), email_(email) {}

// Add a new skill if it doesn't exist
void User::addSkill(const std::string& skill) {
    if (!hasSkill(skill)) {
        skills_.push_back(skill);
    }
}

// Check if user has a skill
bool User::hasSkill(const std::string& skill) const noexcept {
    return std::find(skills_.begin(), skills_.end(), skill) != skills_.end();
}

// Display user info
void User::displayProfile() const {
    std::cout << "Name: " << name_ << "\nEmail: " << email_ << "\nSkills: ";
    if (skills_.empty()) std::cout << "None";
    else {
        for (const auto &s : skills_) std::cout << s << " ";
    }
    std::cout << "\n";
}
