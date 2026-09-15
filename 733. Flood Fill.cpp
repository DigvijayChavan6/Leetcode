class Solution {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    int n, m;

    void dfs(int a, int b, vector<vector<int>>& grid, int color) {
        
        stack<pair<int, int>> st;
        int curColor = grid[a][b];
        grid[a][b] = color;
        st.push({a, b});

        while (!st.empty()) {
            auto [i, j] = st.top();
            st.pop();
            for (int k = 0; k < 4; k++) {
                int r = dx[k] + i;
                int c = dy[k] + j;
                if (r < n && r >= 0 && c < m && c >= 0) {
                    if (grid[r][c] == curColor) {
                        grid[r][c] = color;
                        st.push({r, c});
                    }
                }
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size(), m = image[0].size();
        if(color != image[sr][sc])dfs(sr, sc, image, color);
        return image;
    }
};