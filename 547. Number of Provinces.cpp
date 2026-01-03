class DSU{
    vector<int> size;
    vector<int> parent;
    
    public:
    
    DSU(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }
    
    int find(int u){
        if(u == parent[u]){
            return u;
        }
        return parent[u] = find(parent[u]);
    }
    
    void unio(int u, int v){
        int pu = find(u);
        int pv = find(v);
        
        if(pu == pv)return;
        
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        DSU ob(V);
        
        for(int i = 0; i < V; i++){
            for( int j = 0; j < V; j++){
                if(isConnected[i][j] == 1){
                    ob.unio(i, j);
                }
            }
        }
        
        int cnt = 0;
        
        for(int i = 0; i < V; i++){
            if(ob.find(i) == i){
                cnt++;
            }
        }
        
        return cnt;
    }
};