class Solution {
    // int getMinCost(int i, int j, vector<int> &cts, vector<vector<int>> & dp){
    //     if(i > j)return 0;
    //     if(dp[i][j] != -1)return dp[i][j]; 
    //     int minCost = 1e9;

    //     for(int k = i; k <= j; k++){
    //         int cost = getMinCost(i, k-1, cts, dp) + getMinCost(k+1, j, cts, dp) + 
    //         (cts[j+1] - cts[i-1]);
    //         minCost = min(cost, minCost);
    //     }

    //     return dp[i][j] = minCost;
    // }
public:
    int minCost(int n, vector<int>& cuts) {
        vector<int> cts;
        int len = cuts.size();
        cts.push_back(0);
        for(int val : cuts){
            cts.push_back(val);
        }
        cts.push_back(n);
        sort(cts.begin(), cts.end());
        vector<vector<int>> dp(len+2, vector<int>(len+2, 0));

        for(int i = len; i >= 1; i--){
            for(int j = i; j <= len; j++){
                int minCost = 1e9;
                for(int k = i; k <= j; k++){
                    int cost = dp[i][k-1] + dp[k+1][j] + 
                    (cts[j+1] - cts[i-1]);
                    minCost = min(cost, minCost);
                }
                dp[i][j] = minCost;
            }
        }
        return dp[1][len];
    }
};