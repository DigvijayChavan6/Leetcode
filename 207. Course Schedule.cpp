class Solution {

    bool dfs(int node, vector<vector<int>>& graph, vector<bool>& visited,
             vector<bool>& vis) {
        visited[node] = true;
        vis[node] = true;

        for (int nbr : graph[node]) {
            if (!visited[nbr]) {
                if (dfs(nbr, graph, visited, vis) == false) {
                    return false;
                }
            }else{
                if(vis[nbr] == true){
                    return false;
                }
            }
        }

        vis[node] = false;
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);
        vector<bool> visited(numCourses, false);
        vector<bool> vis(numCourses, false);

        for (int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(i, graph, visited, vis) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};