class Solution {
    int n, m;

    void dfs(int i, vector<vector<int>> &graph, bool visited[]){
        visited[i] = true;
        for(int k = 0; k < m; k++){
            if(graph[i][k] == 1 && !visited[k]){
                dfs(k, graph, visited);
            }
        }
    }

    public : int findCircleNum(vector<vector<int>>& graph) {
        n = graph.size(), m = graph[0].size();
        int count = 0;

        bool visited[200] = {false};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (graph[i][j] == 1 && !visited[i]) {
                    dfs(i, graph, visited);
                    count++;
                }
            }
        }

        return count;
    }
};