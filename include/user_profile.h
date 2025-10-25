#pragma once
#ifndef USER_PROFILE_H
#define USER_PROFILE_H

#include <string>
#include <vector>
#include <iostream>

class User {
private:
    std::string name_;
    std::string email_;
    std::vector<std::string> skills_;
public:
    User() = default;
    User(const std::string& name, const std::string& email);

    // Getters
    const std::string& getName() const noexcept { return name_; }
    const std::string& getEmail() const noexcept { return email_; }
    const std::vector<std::string>& getSkills() const noexcept { return skills_; }

    // Actions
    void addSkill(const std::string& skill);
    bool hasSkill(const std::string& skill) const noexcept;

    // Display
    void displayProfile() const;
};

#endif // USER_PROFILE_H
