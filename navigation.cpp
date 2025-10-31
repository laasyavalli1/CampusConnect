#include "navigation.h"

int main() {
    graph campus;

    campus.addedge("main gate", "admin", 50);
    campus.addedge("admin", "library", 250);
    campus.addedge("admin", "chemical", 100);
    campus.addedge("admin", "nso", 100);
    campus.addedge("admin", "orion", 150);
    campus.addedge("admin", "barn", 50);
    campus.addedge("admin", "logos", 150);
    campus.addedge("admin", "eee", 50);
    campus.addedge("admin", "mech", 100);
    campus.addedge("admin", "mme", 100);
    campus.addedge("admin", "octagon", 100);
    campus.addedge("admin", "prod", 200);
    campus.addedge("admin", "ice", 500);
    campus.addedge("admin", "ojas", 300);
    campus.addedge("admin", "arch", 250);
    campus.addedge("admin", "gjch", 200);
    campus.addedge("admin", "civil", 200);
    campus.addedge("admin", "2k", 600);
    campus.addedge("cse", "library", 150);
    campus.addedge("cse", "eee", 400);
    campus.addedge("cse", "ice", 25);
    campus.addedge("cse", "nso", 300);
    campus.addedge("cse", "chemical", 600);

    string start, end;
    cout << "\nEnter your start landmark: ";
    getline(cin, start);
    cout << "Enter your destination landmark: ";
    getline(cin, end);

    campus.shortestpath(start, end);

    char choice;
    cout << "\nWould you like to view the complete campus map? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        campus.displaymap();
        cout << "\nEnter a landmark to explore nearby buildings (BFS): ";
        cin.ignore();
        string bfsStart;
        getline(cin, bfsStart);
        campus.bfs(bfsStart);
    }
    return 0;
}
