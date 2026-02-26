class Solution {
public:
    int change(int sum, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned long long> dp(sum+1, 0);
        
        for(int s = 0; s <= sum; s++){
            if(s%coins[0] == 0)dp[s] = 1;
            else dp[s] = 0;
        }
        
        for(int i = 1; i < n; i++){
            for(int s = 0; s <= sum; s++){
                unsigned long long take = 0;
                unsigned long long notTake = dp[s];
                if(coins[i] <= s){
                    take = dp[s-coins[i]];
                }
                dp[s] = (take + notTake);
            }
        }
        return dp[sum];
    }
};