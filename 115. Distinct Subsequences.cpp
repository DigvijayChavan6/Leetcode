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