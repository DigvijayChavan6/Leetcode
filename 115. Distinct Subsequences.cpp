class Solution {
    int getCount(int n, int m, string &s, string &t,
    vector<vector<int>> &dp){
        if(m < 0)return 1;
        if(n < 0)return 0;

        if(dp[n][m] != -1)return dp[n][m];

        int match = 0;
        int notMatch = 0;
        if(s[n] == t[m]){
            match = getCount(n-1, m-1, s, t, dp);
        }
        notMatch = getCount(n-1, m, s, t, dp);
        return dp[n][m] = match + notMatch;
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return getCount(n-1, m-1, s, t, dp);
    }
};


class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        int mod = 1e9+7;

        vector<int> curr(m+1, 0), prev(m+1, 0);

        prev[0] = 1;
        curr[0] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int match = 0;
                int notMatch = prev[j];
                if(s[i-1] == t[j-1]) match = prev[j-1];
                curr[j] = (match + notMatch) % mod;
            }
            prev = curr;
        }

        return prev[m];

        // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // for(int i = 0; i <= n; i++) dp[i][0] = 1;

        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= m; j++){
        //         int match = 0;
        //         int notMatch = dp[i-1][j];
        //         if(s[i-1] == t[j-1]) match = dp[i-1][j-1];
        //         dp[i][j] = (match + notMatch) % mod;
        //     }
        // }

        // return dp[n][m];
    }
};