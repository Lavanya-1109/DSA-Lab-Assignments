#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
using namespace std;

class Graph {
private:
    unordered_map<int, vector<int>> adjList; // adjacency list

public:
    // Add edge (undirected graph)
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // BFS traversal from a given start node
    vector<int> bfs(int start) {
        set<int> visited;          // track visited nodes
        queue<int> q;              // queue for BFS
        vector<int> bfsOrder;      // store traversal order

        visited.insert(start);
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfsOrder.push_back(node);

            // explore neighbors
            for (int neighbor : adjList[node]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        return bfsOrder;
    }
};

int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    cout << "BFS Traversal starting from node 0: ";
    vector<int> result = g.bfs(0);

    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}