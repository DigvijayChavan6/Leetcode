class Solution {
public:
    bool isMatch(string pattern, string wild) {
        // int n = wild.size(), m = pattern.size();
        // vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        // dp[0][0] = true;
        // for(int k = 1; k <= n; k++){
        //     dp[k][0] = true;
        //     if(wild[k-1] != '*'){
        //         dp[k][0] = false;
        //         break;
        //     }
        // }
        
        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= m; j++){
        //         if(wild[i-1] == pattern[j-1] || wild[i-1] == '?'){
        //             dp[i][j] = dp[i-1][j-1];
        //         }
        //         else if(wild[i-1] == '*'){
        //             dp[i][j] = dp[i-1][j] || dp[i][j-1]; 
        //         }else{
        //             dp[i][j] = false;
        //         }
        //     }
        // }
        
        // return dp[n][m];

        int n = wild.size(), m = pattern.size();
        vector<bool> prev(m+1, false);
        prev[0] = true;
        
        for(int i = 1; i <= n; i++){
            vector<bool> curr(m+1, false);
            curr[0] = prev[0] && wild[i-1] == '*';
            for(int j = 1; j <= m; j++){
                if(wild[i-1] == pattern[j-1] || wild[i-1] == '?'){
                    curr[j] = prev[j-1];
                }
                else if(wild[i-1] == '*'){
                    curr[j] = prev[j] || curr[j-1]; 
                }else{
                    curr[j] = false;
                }
            }
            prev = curr;
        }
        
        return prev[m];
    }
};