#ifndef GROUP_MANAGEMENT_H
#define GROUP_MANAGEMENT_H

#include "user_profile.h"
#include <string>
#include <vector>

class Group {
private:
    std::string name;
    std::vector<std::string> memberEmails; // store emails to avoid copying users
public:
    Group() = default;
    explicit Group(const std::string& name);

    std::string getName() const;
    void addMember(const std::string& userEmail);
    void removeMember(const std::string& userEmail);
    const std::vector<std::string>& getMembers() const;
    void displayMembers() const; // prints emails (UI later can resolve to names)
};

#endif // GROUP_MANAGEMENT_H
