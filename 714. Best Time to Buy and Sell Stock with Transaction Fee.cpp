class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        // code here
        int n = prices.size();
        vector<int> dp(2, 0), prev(2, 0), old(2, 0);
        int profit = 0;
        int consider = 0;
        int notConsider = 0;

        for(int i = n-1; i >= 0; i--){
            for(int canBuy = 0; canBuy <= 1; canBuy++){
                if(canBuy == 1){
                    consider = -prices[i] + prev[0];
                    notConsider = prev[canBuy];
                }else{
                    consider = prices[i] + old[1];
                    notConsider = prev[canBuy];
                }
                profit = max(consider, notConsider);
                dp[canBuy] = profit;
            }
            old = prev;
            prev = dp;
        }
        return prev[1];
    }
};