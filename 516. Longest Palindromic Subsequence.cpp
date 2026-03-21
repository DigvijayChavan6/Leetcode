class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string k = s;
        int n = k.size(), m = n;
        reverse(s.begin(), s.end());        
        vector<int> curr(n+1, 0), prev(m+1, 0);
           
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int cnt = 0;
                if(s[i-1] == k[j-1]){
                    cnt = 1 + prev[j-1];
                }
        
                cnt = max(cnt, prev[j]);
                cnt = max(cnt, curr[j-1]);
                
                curr[j] = cnt;
            }
            prev = curr;
        }
            
        return curr[m];
    }
};