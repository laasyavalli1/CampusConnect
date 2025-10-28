#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

// Structure to represent each building
struct Building {
    string name;
    string description;
    vector<string> connectedTo;  // adjacency list
};

// Graph class for inside-campus navigation
class CampusMap {
private:
    unordered_map<string, Building> graph;

public:
    void addBuilding(const string &name, const string &desc);
    void addPath(const string &from, const string &to);
    bool buildingExists(const string &name) const;
    void showBuildingDetails(const string &name) const;
    void listAllBuildings() const;
};

#endif
