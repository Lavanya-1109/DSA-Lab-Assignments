#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Graph {
    int V;
    vector<vector<pair<int,int>>> adj; // {neighbor, weight}
public:
    Graph(int _V) : V(_V) {
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected
    }

    void primMST(int start = 0) {
        vector<bool> inMST(V, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, start}); // {weight, node}
        int totalWeight = 0;

        cout << "Prim's MST edges:\n";

        while (!pq.empty()) {
            auto [weight, u] = pq.top();
            pq.pop();

            if (inMST[u]) continue;
            inMST[u] = true;
            totalWeight += weight;

            if (weight != 0) // skip first dummy edge
                cout << "Included node " << u << " with edge weight " << weight << "\n";

            for (auto &[v, w] : adj[u]) {
                if (!inMST[v]) {
                    pq.push({w, v});
                }
            }
        }

        cout << "Total Weight = " << totalWeight << endl;
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 5);
    g.addEdge(2, 4, 11);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 5, 7);

    g.primMST(0);
    return 0;
}