class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j] == 1)count++;
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    if (grid[i][j] == 1) {
                        q.push({i, j});
                        visited[i][j] = true;
                    }
                }
            }
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            count--;

            for (int i = 0; i < 4; i++) {
                int r = dx[i] + x;
                int c = dy[i] + y;

                if (r < n && r >= 0 && c < m && c >= 0 && grid[r][c] == 1 && !visited[r][c]) {
                    q.push({r, c});
                    visited[r][c] = true;
                }
            }
        }

        return count;
    }
};