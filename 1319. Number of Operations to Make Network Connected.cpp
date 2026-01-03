class DSU{
    vector<int> parent, size;
    public:
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    int find(int u){
        if(parent[u] == u){
            return u;
        }
        return parent[u] = find(parent[u]);
    }

    void unite(int u, int v){
        int pu = find(u);
        int pv = find(v);

        if(parent[pu] == parent[pv])return;

        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }else{
            parent[pv] = pu;
            size[pv] += size[pu];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cnt = 0;
        int extraEdges = 0;
        DSU ds(n);
        for(auto edge : connections){
            if(ds.find(edge[0]) != ds.find(edge[1])){
                ds.unite(edge[0], edge[1]);
            }else{
                extraEdges++;
            }
        }

        for(int i = 0; i < n; i++){
            if(ds.find(i) == i){
                cnt++;
            }
        }

        return cnt - 1 <= extraEdges ? cnt - 1 : -1;
    }
};