class Solution {
public:
    int minDistance(string str, string pqr) {
        int n = str.size();
        int m = pqr.size();
        vector<int> curr(m+1, 0), prev(m+1, 0);
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int cnt = 0;
                if(str[i-1] == pqr[j-1]){
                    cnt = 1 + prev[j-1]; 
                }else{
                    cnt = max(cnt, curr[j-1]);
                    cnt = max(cnt, prev[j]);
                }
                curr[j] = cnt;
            }
            prev = curr;
        }
        
        return n + m - (2*curr[m]);
    }
};