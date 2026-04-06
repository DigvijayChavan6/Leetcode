class Solution {
    // int getMax(int i, int canBuy, int tranCount, int n, vector<int> &prices,
    //     vector<vector<vector<int>>> &dp){
    //     if(i == n || tranCount >= 2)return 0;
    //     int profit = 0;
    //     int consider = 0;
    //     int notConsider = 0;
    //     if(dp[i][canBuy][tranCount] != -1)return dp[i][canBuy][tranCount];
    //     if(canBuy == 1){
    //         consider = -prices[i] + getMax(i+1, 0, tranCount, n, prices, dp);
    //         notConsider = getMax(i+1, 1, tranCount, n, prices, dp);
    //     }else{
    //         consider = prices[i] + getMax(i+1, 1, tranCount+1, n, prices, dp);
    //         notConsider = getMax(i+1, 0, tranCount, n, prices, dp);
    //     }
    //     profit = max(consider, notConsider);
    //     return dp[i][canBuy][tranCount] = profit;
    // }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int>(3, 0)));

        for(int i = n-1; i >= 0; i--){
            for(int canBuy = 0; canBuy <= 1; canBuy++){
                for(int tranCount = 0; tranCount <= 2; tranCount++){
                    int profit = 0;
                    int consider = 0;
                    int notConsider = 0;
                    if(tranCount == 2)continue;
                    if(canBuy == 1){
                        consider = -prices[i] + dp[i+1][0][tranCount];
                        notConsider = dp[i+1][1][tranCount];
                    }else{
                        consider = prices[i] + dp[i+1][1][tranCount+1];
                        notConsider = dp[i+1][0][tranCount];
                    }
                    profit = max(consider, notConsider);
                    dp[i][canBuy][tranCount] = profit;
                }
            }
        }

        return dp[0][1][0];
    }
};

class Solution {
    // int getMax(int i, int canBuy, int tranCount, int n, vector<int> &prices,
    //     vector<vector<vector<int>>> &dp){
    //     if(i == n || tranCount >= 2)return 0;
    //     int profit = 0;
    //     int consider = 0;
    //     int notConsider = 0;
    //     if(dp[i][canBuy][tranCount] != -1)return dp[i][canBuy][tranCount];
    //     if(canBuy == 1){
    //         consider = -prices[i] + getMax(i+1, 0, tranCount, n, prices, dp);
    //         notConsider = getMax(i+1, 1, tranCount, n, prices, dp);
    //     }else{
    //         consider = prices[i] + getMax(i+1, 1, tranCount+1, n, prices, dp);
    //         notConsider = getMax(i+1, 0, tranCount, n, prices, dp);
    //     }
    //     profit = max(consider, notConsider);
    //     return dp[i][canBuy][tranCount] = profit;
    // }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> prev(2, vector<int>(3, 0));
        vector<vector<int>> dp(2, vector<int>(3, 0));

        for(int i = n-1; i >= 0; i--){
            for(int canBuy = 0; canBuy <= 1; canBuy++){
                for(int tranCount = 0; tranCount <= 2; tranCount++){
                    int profit = 0;
                    int consider = 0;
                    int notConsider = 0;
                    if(tranCount == 2)continue;
                    if(canBuy == 1){
                        consider = -prices[i] + prev[0][tranCount];
                        notConsider = prev[1][tranCount];
                    }else{
                        consider = prices[i] + prev[1][tranCount+1];
                        notConsider = prev[0][tranCount];
                    }
                    profit = max(consider, notConsider);
                    dp[canBuy][tranCount] = profit;
                }
            }
            prev = dp;
        }

        return prev[1][0];
    }
};