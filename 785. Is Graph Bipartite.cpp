class Solution {
    bool bfs(vector<vector<int>>& graph, int node, vector<int>& visited) {
        queue<pair<int, int>> q;

        q.push({node, 0});

        while (!q.empty()) {
            auto [node, color] = q.front();
            q.pop();

            for (int next : graph[node]) {
                if (visited[next] == -1) {
                    q.push({next, 1 - color});
                    visited[next] = 1 - color;
                } else {
                    if (visited[next] != 1 - color) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> visited(n, -1);

        for (int i = 0; i < n; i++) {
            if (visited[i] == -1 && !bfs(graph, i, visited)) {
                return false;
            }
        }

        return true;
    }
};