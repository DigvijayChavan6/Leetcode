class Solution {
    int n, m;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    bool bfs(int a, int b, vector<vector<char>>& grid,
             vector<vector<bool>>& visited) {
        visited[a][b] = true;

        queue<pair<pair<int, int>, pair<int, int>>> q;

        q.push({{-1, -1}, {a, b}});

        while (!q.empty()) {
            auto [px, py] = q.front().first;
            auto [x, y] = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int r = dx[i] + x;
                int c = dy[i] + y;

                if (r < n && r >= 0 && c < m && c >= 0 &&
                    grid[r][c] == grid[x][y] && !(r == px && c == py)) {
                    if (visited[r][c]) {
                        return true;
                    }
                    q.push({{x, y}, {r, c}});
                    visited[r][c] = true;
                }
            }
        }

        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && bfs(i, j, grid, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
};