class Solution {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int freshCount = 0;
        vector<vector<int>> temp = grid;
        queue<pair<int, pair<int, int>>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({0, {i, j}});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        while (!q.empty()) {
            auto [level, pos] = q.front();
            auto [x, y] = pos;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int r = dx[k] + x;
                int c = dy[k] + y;
                if (r < n && r >= 0 && c < m && c >= 0 && temp[r][c] == 1) {
                    temp[r][c] = 2;
                    freshCount--;
                    if (freshCount == 0)
                        return level + 1;
                    q.push({level + 1, {r, c}});
                }
            }
        }

        return freshCount == 0 ? 0 : -1;
    }
};