class Solution {
    queue<pair<int, pair<int, int>>> dfs(vector<vector<int>>& graph, int n,
                                         int m) {
        stack<pair<int, int>> st;
        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (graph[i][j] == 1) {
                    st.push({i, j});
                    graph[i][j] = 2;
                    break;
                }
            }
            if (!st.empty())
                break;
        }

        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};

        while (!st.empty()) {
            int a = st.top().first;
            int b = st.top().second;
            st.pop();

            for (int i = 0; i < 4; i++) {
                int r = row[i] + a;
                int c = col[i] + b;
                if (r >= 0 && r < n && c >= 0 && c < m) {
                    if (graph[r][c] == 0) {
                        q.push({1, {r, c}});
                        graph[r][c] = -1;
                    } else if (graph[r][c] == 1) {
                        graph[r][c] = 2;
                        st.push({r, c});
                    }
                }
            }
        }

        return q;
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        vector<vector<int>> graph = grid;
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, pair<int, int>>> q = dfs(graph, n, m);

        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int length = q.front().first;
            int a = q.front().second.first;
            int b = q.front().second.second;

            q.pop();

            for (int i = 0; i < 4; i++) {
                int r = row[i] + a;
                int c = col[i] + b;
                if (r >= 0 && r < n && c >= 0 && c < m) {
                    if (graph[r][c] == 0) {
                        q.push({length + 1, {r, c}});
                        graph[r][c] = -1;
                    } else if (graph[r][c] == 1) {
                        return length;
                    }
                }
            }
        }

        return 0;
    }
};