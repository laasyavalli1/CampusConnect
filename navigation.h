#ifndef navigation_H
#define navigation_H

#include <bits/stdc++.h>
using namespace std;

struct edge {
    string dest;
    int distance;
};

class graph {
    unordered_map<string, vector<edge>> adjlist;

public:
    void addedge(string src, string dest, int distance) {
        adjlist[src].push_back({dest, distance});
        adjlist[dest].push_back({src, distance});
    }

    void displaymap() {
        cout << "\nComplete Campus Map:\n";
        for (auto &p : adjlist) {
            cout << "  " << p.first << " -> ";
            for (auto &edge : p.second)
                cout << "(" << edge.dest << ", " << edge.distance << "m) ";
            cout << endl;
        }
    }

    void bfs(string start) {
        if (adjlist.find(start) == adjlist.end()) {
            cout << "Landmark not found!\n";
            return;
        }

        unordered_map<string, bool> visited;
        queue<string> q;

        visited[start] = true;
        q.push(start);

        cout << "\nBFS Traversal:\n";

        while (!q.empty()) {
            string current = q.front(); q.pop();
            cout << "  " << current << " ";

            for (auto &edge : adjlist[current]) {
                if (!visited[edge.dest]) {
                    visited[edge.dest] = true;
                    q.push(edge.dest);
                }
            }
        }
        cout << endl;
    }

    void shortestpath(string start, string end) {
        if (adjlist.find(start) == adjlist.end() || adjlist.find(end) == adjlist.end()) {
            cout << "Invalid start or destination landmark!\n";
            return;
        }

        unordered_map<string, int> dist;
        unordered_map<string, string> parent;
        for (auto &p : adjlist)
            dist[p.first] = INT_MAX;

        dist[start] = 0;
        parent[start] = "";

        using pii = pair<int, string>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [currentDist, curr] = pq.top(); pq.pop();

            for (auto &edge : adjlist[curr]) {
                if (dist[curr] + edge.distance < dist[edge.dest]) {
                    dist[edge.dest] = dist[curr] + edge.distance;
                    parent[edge.dest] = curr;
                    pq.push({dist[edge.dest], edge.dest});
                }
            }
        }

        if (dist[end] == INT_MAX) {
            cout << "No path found from " << start << " to " << end << "!\n";
            return;
        }

        vector<string> path;
        for (string at = end; at != ""; at = parent[at])
            path.push_back(at);
        reverse(path.begin(), path.end());

        cout << "\nShortest path from " << start << " to " << end << ":\n  ";
        for (size_t i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << " -> ";
        }
        cout << "\nTotal distance: " << dist[end] << " meters\n";
    }
};

#endif
