#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

struct Cell {
    int cost, x, y;
    bool operator>(const Cell& other) const {
        return cost > other.cost;
    }
};

class GridGraph {
    int m, n;
    vector<vector<int>> grid;
    vector<vector<int>> dist;
    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}}; // down, up, right, left

public:
    GridGraph(vector<vector<int>> g) {
        grid = g;
        m = g.size();
        n = g[0].size();
        dist.assign(m, vector<int>(n, numeric_limits<int>::max()));
    }

    int dijkstra() {
        priority_queue<Cell, vector<Cell>, greater<Cell>> pq;
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty()) {
            Cell cur = pq.top();
            pq.pop();

            int x = cur.x, y = cur.y;
            if (x == m-1 && y == n-1) return cur.cost; // reached destination

            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newCost = cur.cost + grid[nx][ny];
                    if (newCost < dist[nx][ny]) {
                        dist[nx][ny] = newCost;
                        pq.push({newCost, nx, ny});
                    }
                }
            }
        }
        return -1; // unreachable
    }
};

int main() {
    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    GridGraph g(grid);
    cout << "Minimum cost path = " << g.dijkstra() << endl;
    return 0;
}