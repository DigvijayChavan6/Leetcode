class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int distance = 0;
        int n = graph.size();
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));

        int allVisited = (1 << n) - 1;

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            int mask = 1 << i;
            q.push({i, mask});
            visited[i][mask] = true;
        }

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                auto [node, mask] = q.front();
                q.pop();

                if (mask == allVisited)
                    return distance;

                for (int nbr : graph[node]) {
                    int newMask = mask | (1 << nbr);
                    if (!visited[nbr][newMask]) {
                        q.push({nbr, newMask});
                        visited[nbr][newMask] = true;
                    }
                }
            }

            distance++;
        }

        return distance;
    }
};