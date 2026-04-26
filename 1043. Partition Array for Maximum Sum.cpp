class Solution {
    int maxSum(int i, int k, int n, vector<int> &arr, vector<int> &dp){
        if(i == n)return 0;
        if(dp[i] != -1)return dp[i];
        int sum = 0;
        int mx = 0;
        for(int j = i; j < i+k && j < n; j++){
            mx = max(mx, arr[j]);
            int take = mx * (j - i + 1) + maxSum(j+1, k, n, arr, dp);
            sum = max(sum, take);
        }

        return dp[i] = sum;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        // vector<int> dp(n, -1);
        vector<int> dp(n+1, 0);
        for(int i = n-1; i >= 0; i--){
            int sum = 0;
            int mx = 0;
            for(int j = i; j < i+k && j < n; j++){
                mx = max(mx, arr[j]);
                int take = mx * (j - i + 1) + dp[j+1];
                sum = max(sum, take);
            }
            dp[i] = sum;
        }
        return dp[0];
    }
};