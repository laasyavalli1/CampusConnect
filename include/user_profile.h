#ifndef USER_PROFILE_H
#define USER_PROFILE_H

#include <string>
#include <vector>

class User {
private:
    std::string name;
    std::string email; // unique identifier
    std::vector<std::string> skills;
public:
    User() = default;
    User(const std::string& name, const std::string& email);

    // getters
    std::string getName() const;
    std::string getEmail() const;
    const std::vector<std::string>& getSkills() const;

    // actions
    void addSkill(const std::string& skill);
    bool hasSkill(const std::string& skill) const;

    // display
    void displayProfile() const;
};

#endif // USER_PROFILE_H
