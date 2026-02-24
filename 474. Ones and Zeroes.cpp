class Solution {
    int getMaxLen(int len, int m, int n, vector<pair<int, int>> &cnt,
    vector<vector<vector<int>>>& dp){
        if(len == 0){
            if(cnt[0].first <= m && cnt[0].second <= n){
                return 1;
            }else{
                return 0;
            }
        }
        if(dp[len][m][n] != -1)return dp[len][m][n];
        int take = 0;
        int notTake = getMaxLen(len-1, m, n, cnt, dp);
        if(cnt[len].first <= m && cnt[len].second <= n){
            take = 1 + getMaxLen(len-1, m-cnt[len].first, n-cnt[len].second, cnt, dp);
        }
        return dp[len][m][n] = max(take, notTake);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<pair<int, int>> cnt;
        for(int i = 0; i < len; i++){
            string str = strs[i];
            int ones = 0, zeroes = 0;
            for(char &c : str){
                if(c == '1')ones++;
                else zeroes++;
            }
            cnt.push_back({zeroes, ones});
        }
        
        vector<vector<vector<int>>> dp(len, vector<vector<int>>(m+1, vector<int>(n+1, -1)));

        return getMaxLen(len-1, m, n, cnt, dp);
    }
};









class Solution {
    // int getMaxLen(int len, int m, int n, vector<pair<int, int>> &cnt,
    // vector<vector<vector<int>>>& dp){
    //     if(len == 0){
    //         if(cnt[0].first <= m && cnt[0].second <= n){
    //             return 1;
    //         }else{
    //             return 0;
    //         }
    //     }
    //     if(dp[len][m][n] != -1)return dp[len][m][n];
    //     int take = 0;
    //     int notTake = getMaxLen(len-1, m, n, cnt, dp);
    //     if(cnt[len].first <= m && cnt[len].second <= n){
    //         take = 1 + getMaxLen(len-1, m-cnt[len].first, n-cnt[len].second, cnt, dp);
    //     }
    //     return dp[len][m][n] = max(take, notTake);
    // }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<pair<int, int>> cnt;
        for(int i = 0; i < len; i++){
            string str = strs[i];
            int ones = 0, zeroes = 0;
            for(char &c : str){
                if(c == '1')ones++;
                else zeroes++;
            }
            cnt.push_back({zeroes, ones});
        }
        
        vector<vector<vector<int>>> dp(len, vector<vector<int>>(m+1, vector<int>(n+1, 0)));

        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(cnt[0].first <= i && cnt[0].second <= j){
                    dp[0][i][j] = 1;
                }else{
                    dp[0][i][j] = 0;
                }
            }
        }

        for(int i = 1; i < len; i++){
            for(int j = 0; j <= m; j++){
                for(int k = 0; k <= n; k++){
                    int take = 0;
                    int notTake = dp[i-1][j][k];
                    if(cnt[i].first <= j && cnt[i].second <= k){
                        take = 1 + dp[i-1][j-cnt[i].first][k-cnt[i].second];
                    }
                    dp[i][j][k] = max(take, notTake);
                }
            }
        }

        return dp[len-1][m][n];
        //return getMaxLen(len-1, m, n, cnt, dp);
    }
};