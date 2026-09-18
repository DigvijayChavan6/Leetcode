class Solution {

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 0));
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        queue<pair<int, pair<int, int>>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({0, {i, j}});
                    dist[i][j] = 0;
                    visited[i][j] = true;
                }
            }
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};

        while (!q.empty()) {
            auto [dst, pos] = q.front();
            auto [x, y] = pos;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int r = dx[i] + x;
                int c = dy[i] + y;

                if (r < n && r >= 0 && c < m && c >= 0 && !visited[r][c]) {
                    q.push({dst + 1, {r, c}});
                    dist[r][c] = dst + 1;
                    visited[r][c] = true;
                }
            }
        }

        return dist;
    }
};