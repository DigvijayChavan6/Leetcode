
class DSU{
    public:
    vector<int> size;
    vector<int> parent;
    
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
    
    void unite(int u, int v){
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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        
        int maxRow = stones[0][0];
        int maxCol = stones[0][1];
        
        for(auto p : stones){
            maxRow = max(maxRow, p[0]);
            maxCol = max(maxCol, p[1]);
        }
        
        
        DSU ds(maxRow + maxCol + 1);
        
        unordered_set<int> st;
        
        for(auto p : stones){
            ds.unite(p[0], p[1] + maxRow + 1);
            st.insert(p[0]);
            st.insert(p[1] + maxRow + 1);
        }
        
        int component = 0;
        
        for(int i : st){
            if(ds.find(i) == i){
                ++component;
            }
        }
        
        return n - component;
    }
};