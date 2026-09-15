class Solution {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    int n, m;

    void dfs(int a, int b, vector<vector<char>>& grid,
             vector<vector<bool>>& visited) {

        stack<pair<int, int>> st;
        visited[a][b] = true;
        st.push({a, b});

        while (!st.empty()) {
            auto [i, j] = st.top();
            st.pop();
            for (int k = 0; k < 4; k++) {
                int r = dx[k] + i;
                int c = dy[k] + j;
                if (r < n && r >= 0 && c < m && c >= 0) {
                    if (grid[r][c] == '1' && !visited[r][c]) {
                        visited[r][c] = true;
                        st.push({r, c});
                    }
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(i, j, grid, visited);
                    count++;
                }
            }
        }

        return count;
    }
};