#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // adjacency list: node -> {neighbor, weight}
        vector<vector<pair<int,int>>> adj(N+1);
        for (auto &edge : times) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
        }

        // distances initialized to infinity
        vector<int> dist(N+1, numeric_limits<int>::max());
        dist[K] = 0;

        // min-heap {distance, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, K});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue; // skip outdated entry

            for (auto &[v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        // find maximum distance
        int maxDist = 0;
        for (int i = 1; i <= N; i++) {
            if (dist[i] == numeric_limits<int>::max()) return -1; // unreachable
            maxDist = max(maxDist, dist[i]);
        }
        return maxDist;
    }
};

int main() {
    int N = 4, K = 2;
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};

    Solution sol;
    cout << sol.networkDelayTime(times, N, K) << endl;
    return 0;
}