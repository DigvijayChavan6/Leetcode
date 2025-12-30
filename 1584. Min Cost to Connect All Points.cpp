
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        int sum = 0;
        
        vector<vector<pair<int, int>>> graph(V);
        
        for(auto e : edges){
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }
        
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<>
        > pq;
        
        vector<int> visited(V, false);
        
        pq.push({0, 0});
        
        while(!pq.empty()){
            int w = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(visited[node])continue;
            
            sum += w;
            visited[node] = true;
            
            for(auto p : graph[node]){
                if(!visited[p.first]){
                    pq.push({p.second, p.first});
                }
            }
        }
        
        return sum;
    }
};