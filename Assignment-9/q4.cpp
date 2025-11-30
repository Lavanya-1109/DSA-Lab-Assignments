#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>
using namespace std;

class Graph {
    int V; // number of vertices
    vector<vector<pair<int,int>>> adj; // adjacency list {neighbor, weight}

public:
    Graph(int _V) : V(_V) {
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected graph
    }

    void dijkstra(int src) {
        vector<int> dist(V, numeric_limits<int>::max());
        dist[src] = 0;

        // Min-heap: {distance, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > dist[u]) continue; // skip outdated entry

            for (auto &[v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Shortest distances from source " << src << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << " : ";
            if (dist[i] == numeric_limits<int>::max())
                cout << "INF\n";
            else
                cout << dist[i] << "\n";
        }
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 5);
    g.addEdge(1, 3, 10);
    g.addEdge(2, 4, 3);
    g.addEdge(4, 3, 4);
    g.addEdge(3, 5, 11);

    g.dijkstra(0); // shortest paths from node 0
    return 0;
}