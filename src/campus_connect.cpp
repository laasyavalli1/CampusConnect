#include "campus_connect.h"
#include "user_profile.h"
#include <algorithm>
#include <iostream>

// Create a new user; returns false if email already exists
bool CampusConnect::createUser(const std::string &name, const std::string &email) {
    if (users_.find(email) != users_.end()) return false;
    users_[email] = std::make_unique<User>(name, email);
    return true;
}

// Add skill to existing user; returns false if user not found or skill exists
bool CampusConnect::addSkill(const std::string &email, const std::string &skill) {
    auto it = users_.find(email);
    if (it == users_.end()) return false;
    it->second->addSkill(skill);
    return true;
}

// List all user emails
std::vector<std::string> CampusConnect::listUsers() const {
    std::vector<std::string> result;
    for (const auto &p : users_) result.push_back(p.first);
    return result;
}

// Get pointer to user; nullptr if not found
User* CampusConnect::getUser(const std::string &email) {
    auto it = users_.find(email);
    return (it != users_.end()) ? it->second.get() : nullptr;
}
