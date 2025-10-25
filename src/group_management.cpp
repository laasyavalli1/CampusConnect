#include "group_management.h"
#include <algorithm>
#include <iostream>

Group::Group(const std::string& name) : name(name) {}

void Group::addMember(const std::string& userEmail) {
    if (std::find(memberEmails.begin(), memberEmails.end(), userEmail) == memberEmails.end())
        memberEmails.push_back(userEmail);
}

void Group::removeMember(const std::string& userEmail) {
    auto it = std::remove(memberEmails.begin(), memberEmails.end(), userEmail);
    memberEmails.erase(it, memberEmails.end());
}

void Group::displayMembers() const {
    std::cout << "Group: " << name << "\nMembers:\n";
    if (memberEmails.empty()) std::cout << "  None\n";
    else {
        for (const auto& email : memberEmails)
            std::cout << "  " << email << "\n";
    }
}
