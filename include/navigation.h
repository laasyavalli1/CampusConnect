#pragma once
#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <limits>
#include <utility>

struct Node {
    std::string name;
    explicit Node(std::string n) : name(std::move(n)) {}
};

struct Edge {
    std::string from;
    std::string to;
    int weight;
    Edge(std::string f, std::string t, int w)
        : from(std::move(f)), to(std::move(t)), weight(w) {}
};

class Graph {
private:
    std::unordered_map<std::string, std::vector<std::pair<std::string,int>>> adjList_;
public:
    void addNode(const std::string &name);
    void addEdge(const std::string &from,const std::string &to,int weight);
    std::vector<std::string> BFS(const std::string &start,const std::string &target);
    std::vector<std::string> DFS(const std::string &start,const std::string &target);
    std::vector<std::string> Dijkstra(const std::string &start,const std::string &target);
};

#endif // NAVIGATION_H
