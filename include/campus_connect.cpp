#ifndef CAMPUS_CONNECT_H
#define CAMPUS_CONNECT_H

#include <string>
#include <vector>
#include <unordered_map>

struct User {
    std::string name;
    std::string email;
    std::string skill;

    void displayProfile() const;
};

class CampusConnect {
public:
    bool createUser(const std::string &name, const std::string &email);
    bool addSkill(const std::string &email, const std::string &skill);
    std::vector<std::string> listUsers() const;
    User* getUser(const std::string &email);

private:
    std::unordered_map<std::string, User> users;
};

#endif
