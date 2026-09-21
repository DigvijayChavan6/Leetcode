class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> gra(n);
        vector<int> indegree(n, 0);

        for(int i = 0; i < n; i++){
            for(int nbr : graph[i]){
                gra[nbr].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;

        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> topo;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(int nbr : gra[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0)q.push(nbr);
            }
        }

        sort(topo.begin(), topo.end());

        return topo;
    }
};