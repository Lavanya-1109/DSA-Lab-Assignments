#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
    int M, N;
    vector<vector<int>> grid;
    vector<vector<bool>> visited;
    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

    void bfs(int x, int y) {
        queue<pair<int,int>> q;
        q.push({x,y});
        visited[x][y] = true;

        while (!q.empty()) {
            auto [cx, cy] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) {
                int nx = cx + dx, ny = cy + dy;
                if (nx >= 0 && ny >= 0 && nx < M && ny < N &&
                    grid[nx][ny] == 1 && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

public:
    Solution(vector<vector<int>> g) {
        grid = g;
        M = g.size();
        N = g[0].size();
        visited.assign(M, vector<bool>(N, false));
    }

    int countIslands() {
        int islands = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    bfs(i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
};

int main() {
    vector<vector<int>> grid = {
        {1,1,0},
        {0,1,0},
        {1,0,1}
    };

    Solution sol(grid);
    cout << "Number of islands = " << sol.countIslands() << endl;
    return 0;
}