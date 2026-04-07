class Solution {
    int getMax(int i, int canBuy, int n, vector<int> &prices,
    vector<vector<int>> &dp){
        if(i >= n)return 0;
        int profit = 0;
        int consider = 0;
        int notConsider = 0;

        if(dp[i][canBuy] != -1)return dp[i][canBuy];

        if(canBuy == 1){
            consider = -prices[i] + getMax(i+1, 0, n, prices, dp);
            notConsider = getMax(i+1, canBuy, n, prices, dp);
        }else{
            consider = prices[i] + getMax(i+2, 1, n, prices, dp);
            notConsider = getMax(i+1, canBuy, n, prices, dp);
        }
        profit = max(consider, notConsider);
        return dp[i][canBuy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return getMax(0, 1, n, prices, dp);
    }
};