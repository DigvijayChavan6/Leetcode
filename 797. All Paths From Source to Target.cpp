class Solution {
    void dfs(int node, int n, vector<vector<int>>& graph, vector<vector<int>>& allPaths, vector<int> &path,
             vector<bool>& visited) {
        visited[node] = true;
        path.push_back(node);
        if(node == n-1){
            allPaths.push_back(path);
        }

        for(int nbr : graph[node]){
            if(!visited[nbr]){
                dfs(nbr, n, graph, allPaths, path, visited);
            }
        }

        visited[node] = false;
        path.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> allPaths;
        vector<int> path;
        int n = graph.size();
        vector<bool> visited(n, false);

        dfs(0, n, graph, allPaths, path, visited);

        return allPaths;
    }
};