#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Graph {
    int V;
    unordered_map<int, vector<int>> adj;

    void dfs(int node, set<int>& visited) {
        visited.insert(node);
        for (int neighbor : adj[node]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(neighbor, visited);
            }
        }
    }

public:
    Graph(int _V) : V(_V) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    int countConnectedComponents() {
        set<int> visited;
        int components = 0;

        for (int i = 0; i < V; i++) {
            if (visited.find(i) == visited.end()) {
                dfs(i, visited);
                components++;
            }
        }
        return components;
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    Graph g(V);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << g.countConnectedComponents() << endl;
    return 0;
}