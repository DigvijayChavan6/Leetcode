class Solution {
    int timer = 1;

    void dfs(int node, int parent, vector<int> &vis,
             vector<int> &ts, vector<int> &lw,
             vector<vector<int>> &adj,
             vector<vector<int>> &brds) {

        vis[node] = 1;
        ts[node] = lw[node] = timer++;

        for (int it : adj[node]) {
            if (it == parent) continue;

            if (!vis[it]) {
                dfs(it, node, vis, ts, lw, adj, brds);
                lw[node] = min(lw[node], lw[it]);

                if (lw[it] > ts[node]) {
                    brds.push_back({node, it});
                }
            } else {
                lw[node] = min(lw[node], ts[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        vector<vector<int>> adj(n);

        for (auto &it : con) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<vector<int>> brds;
        vector<int> vis(n, 0), ts(n, 0), lw(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, vis, ts, lw, adj, brds);
            }
        }

        return brds;
    }
};
