class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0];
        int maxProfit = 0;
        for(int i = 1; i < prices.size(); i++){
            if(maxProfit < prices[i] - mn){
                maxProfit = prices[i] - mn;
            }
            mn = min(mn, prices[i]);
        }
        return maxProfit;
    }
};

class Solution {
    // int getMax(int i, int n, int flag, vector<int> &prices,
    //     vector<vector<int>> &dp){
    //     if(i == n)return 0;
    //     if(dp[i][flag] != -1)return dp[i][flag];
    //     int profit = 0;
    //     if(flag == 1){
    //         profit = max(-prices[i] + getMax(i+1, n, 0, prices, dp), getMax(i+1, n, 1, prices, dp));
    //     }else{
    //         profit = max(prices[i] + getMax(i+1, n, 1, prices, dp), getMax(i+1, n, 0, prices, dp));
    //     }
    //     return dp[i][flag] = profit;
    // }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> next(2, 0);
        for(int i = n-1; i >= 0; i--){
            vector<int> curr(2, 0);
            for(int flag = 0; flag <= 1; flag++){
                int profit = 0;
                if(flag == 1){
                    profit = max(-prices[i] + next[0], next[1]);
                }else{
                    profit = max(prices[i] + next[1], next[0]);
                }
                curr[flag] = profit;
            }
            next = curr;
        }
        return next[1];
    }
};