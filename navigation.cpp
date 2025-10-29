#include "navigation.h"

void CampusMap::addBuilding(const string &name, const string &desc) {
    graph[name] = {name, desc, {}};
}

void CampusMap::addPath(const string &from, const string &to) {
    graph[from].connectedTo.push_back(to);
    graph[to].connectedTo.push_back(from); // bidirectional path
}

bool CampusMap::buildingExists(const string &name) const {
    return graph.find(name) != graph.end();
}

void CampusMap::showBuildingDetails(const string &name) const {
    auto it = graph.find(name);
    if (it == graph.end()) {
        cout << "Building not found.\n";
        return;
    }
    const Building &b = it->second;
    cout << "\n📍 " << b.name << "\n";
    cout << "ℹ️ Description: " << b.description << "\n";
    cout << "Connected To: ";
    for (auto &adj : b.connectedTo) cout << adj << " ";
    cout << "\n";
}

void CampusMap::listAllBuildings() const {
    cout << "Buildings in Campus:\n";
    for (auto &pair : graph)
        cout << "- " << pair.first << "\n";
}
