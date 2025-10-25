#include "navigation.h"
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>

void Graph::addNode(const std::string &name){
    if(adjList.find(name)==adjList.end()) adjList[name]={};
}

void Graph::addEdge(const std::string &from,const std::string &to,int weight){
    adjList[from].push_back({to,weight});
    adjList[to].push_back({from,weight});
}

std::vector<std::string> Graph::BFS(const std::string &start,const std::string &target){
    std::queue<std::string> q;
    std::unordered_map<std::string,std::string> parent;
    std::set<std::string> visited;
    q.push(start); visited.insert(start);

    while(!q.empty()){
        std::string cur=q.front(); q.pop();
        if(cur==target) break;
        for(auto &neighbor:adjList[cur]){
            if(visited.find(neighbor.first)==visited.end()){
                visited.insert(neighbor.first);
                parent[neighbor.first]=cur;
                q.push(neighbor.first);
            }
        }
    }

    std::vector<std::string> path;
    if(visited.find(target)==visited.end()) return path;
    for(std::string at=target; at!=start; at=parent[at]) path.push_back(at);
    path.push_back(start);
    std::reverse(path.begin(),path.end());
    return path;
}

// DFS
std::vector<std::string> Graph::DFS(const std::string &start,const std::string &target){
    std::stack<std::string> s;
    std::set<std::string> visited;
    std::unordered_map<std::string,std::string> parent;
    s.push(start); visited.insert(start);

    while(!s.empty()){
        std::string cur=s.top(); s.pop();
        if(cur==target) break;
        for(auto &neighbor:adjList[cur]){
            if(visited.find(neighbor.first)==visited.end()){
                visited.insert(neighbor.first);
                parent[neighbor.first]=cur;
                s.push(neighbor.first);
            }
        }
    }

    std::vector<std::string> path;
    if(visited.find(target)==visited.end()) return path;
    for(std::string at=target; at!=start; at=parent[at]) path.push_back(at);
    path.push_back(start);
    std::reverse(path.begin(),path.end());
    return path;
}

// Dijkstra
std::vector<std::string> Graph::Dijkstra(const std::string &start,const std::string &target){
    std::map<std::string,int> dist;
    std::map<std::string,std::string> parent;
    for(auto &p:adjList) dist[p.first]=std::numeric_limits<int>::max();
    dist[start]=0;
    std::set<std::pair<int,std::string>> pq;
    pq.insert({0,start});

    while(!pq.empty()){
        auto [d,cur]=*pq.begin(); pq.erase(pq.begin());
        if(cur==target) break;
        for(auto &neighbor:adjList[cur]){
            int newDist=d+neighbor.second;
            if(newDist<dist[neighbor.first]){
                pq.erase({dist[neighbor.first],neighbor.first});
                dist[neighbor.first]=newDist;
                parent[neighbor.first]=cur;
                pq.insert({newDist,neighbor.first});
            }
        }
    }

    std::vector<std::string> path;
    if(dist[target]==std::numeric_limits<int>::max()) return path;
    for(std::string at=target; at!=start; at=parent[at]) path.push_back(at);
    path.push_back(start);
    std::reverse(path.begin(),path.end());
    return path;
}

