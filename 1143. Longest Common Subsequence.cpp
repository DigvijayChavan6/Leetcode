class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int match = 0;
                int notMatch = 0;
                if(s1[i-1] == s2[j-1]){
                    match = 1 + dp[i-1][j-1];
                }else{
                    notMatch = max(dp[i-1][j], dp[i][j-1]);
                }
                dp[i][j] = max(match, notMatch);
            }
        }
        
        return dp[n][m];
    }
};