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
    vector<vector<string>> accMerge(vector<vector<string>>& arr) {
        // code here
        int n = arr.size();
        
        unordered_map<string, int> mp;
        
        DSU ds(n);
        
        for(int i = 0; i < n; i++){
            for(int j = 1; j < arr[i].size(); j++){
                if(mp.find(arr[i][j]) == mp.end()){
                    mp[arr[i][j]] = i;
                }else{
                    ds.unite(i, mp[arr[i][j]]);
                }
            }
        }
        
        vector<vector<string>> lt(n);
        
        for(auto it : mp){
            lt[ds.find(it.second)].push_back(it.first);
        }
        
        vector<vector<string>> ans;
        
        for(int i = 0; i < n; i++){
            if(lt[i].empty())continue;
            vector<string> temp;
            temp.push_back(arr[i][0]);
            sort(lt[i].begin(), lt[i].end());
            for(auto &mail : lt[i]){
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};



