#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <set>
using namespace std;

class Graph {
private:
    unordered_map<int, vector<int>> adjList;

public:
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // undirected
    }

    vector<int> dfsIterative(int start) {
        set<int> visited;
        stack<int> st;
        vector<int> dfsOrder;

        st.push(start);

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (visited.find(node) == visited.end()) {
                visited.insert(node);
                dfsOrder.push_back(node);

                // push neighbors (reverse order for consistent traversal)
                for (auto it = adjList[node].rbegin(); it != adjList[node].rend(); ++it) {
                    if (visited.find(*it) == visited.end()) {
                        st.push(*it);
                    }
                }
            }
        }
        return dfsOrder;
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

    cout << "DFS Iterative Traversal starting from node 0: ";
    vector<int> result = g.dfsIterative(0);

    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}