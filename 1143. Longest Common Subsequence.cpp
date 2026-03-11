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




class Solution {
    // int getCount(int n, int m, string &a, string &b,
    // vector<vector<int>> &dp){
    //     if(n < 0 || m < 0){
    //         return 0;
    //     }
        
    //     if(dp[n][m] != -1)return dp[n][m];
        
    //     int match = 0;
    //     int notMatch = 0;
    //     if(a[n] == b[m]){
    //         match = 1 + getCount(n-1, m-1, a, b, dp);
    //     }else{
    //         notMatch = max(getCount(n-1, m, a, b, dp), getCount(n, m-1, a, b, dp));
    //     }
    //     return dp[n][m] = max(match, notMatch);
    // }
  public:
    int lcs(string &s1, string &s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        //vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        vector<int> curr(m+1, 0), prev(m+1, 0);
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int match = 0;
                int notMatch = 0;
                if(s1[i-1] == s2[j-1]){
                    match = 1 + prev[j-1];
                }else{
                    notMatch = max(prev[j], curr[j-1]);
                }
                curr[j] = max(match, notMatch);
            }
            swap(curr, prev);
        }
        
        return prev[m];
    }
};
