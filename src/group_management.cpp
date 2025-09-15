#include "group_management.h"
#include <iostream>
#include <algorithm>

Group::Group(const std::string& n) : name(n) {}

std::string Group::getName() const { return name; }

void Group::addMember(const std::string& userEmail) {
    if (std::find(memberEmails.begin(), memberEmails.end(), userEmail) == memberEmails.end())
        memberEmails.push_back(userEmail);
}

void Group::removeMember(const std::string& userEmail) {
    auto it = std::find(memberEmails.begin(), memberEmails.end(), userEmail);
    if (it != memberEmails.end()) memberEmails.erase(it);
}

const std::vector<std::string>& Group::getMembers() const { return memberEmails; }

void Group::displayMembers() const {
    std::cout << "Group: " << name << "\nMembers:\n";
    if (memberEmails.empty()) std::cout << " (no members)\n";
    else {
        for (const auto &e : memberEmails) std::cout << " - " << e << "\n";
    }
}
