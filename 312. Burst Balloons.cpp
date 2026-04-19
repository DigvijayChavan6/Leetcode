// User function Template for C++
class Solution {
    // int getMaxCoins(int i, int j, vector<int> &blns, vector<vector<int>> & dp){
    //     if(i > j)return 0;
    //     if(dp[i][j] != -1)return dp[i][j];
    //     int maxCoins = 0;
    //     for(int k = i; k <= j; k++){
    //         int coins = getMaxCoins(i, k-1, blns, dp) + getMaxCoins(k+1, j, blns, dp) + 
    //                     blns[i-1] * blns[k] * blns[j+1];
    //         maxCoins = max(maxCoins, coins);
    //     }
    //     return dp[i][j] = maxCoins;
    // }
  public:
    int maxCoins(vector<int> &a) {
        // write your code here
        // int n = N + 2;
        // vector<int> blns(n, 1);
        // vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
        // for(int i = 0; i < N; i++){
        //     blns[i+1] = a[i];
        // }
        // return getMaxCoins(1, N, blns, dp);
        int N = a.size();
        int n = N + 2;
        vector<int> blns(n, 1);
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        for(int i = 0; i < N; i++){
            blns[i+1] = a[i];
        }
        
        for(int i = N; i >= 1; i--){
            for(int j = i; j <= N; j++){
                int maxCoins = 0;
                for(int k = i; k <= j; k++){
                    int coins = dp[i][k-1] + dp[k+1][j] + 
                        blns[i-1] * blns[k] * blns[j+1];
                    maxCoins = max(maxCoins, coins);
                }
                dp[i][j] = maxCoins;
            }
        }
        
        return dp[1][N];
    }
};