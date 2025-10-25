#pragma once
#ifndef CAMPUS_CONNECT_H
#define CAMPUS_CONNECT_H

#include "user_profile.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

class CampusConnect {
private:
    std::unordered_map<std::string, std::unique_ptr<User>> users_;
public:
    bool createUser(const std::string &name, const std::string &email);
    bool addSkill(const std::string &email, const std::string &skill);
    std::vector<std::string> listUsers() const;
    User* getUser(const std::string &email);
};

#endif // CAMPUS_CONNECT_H
