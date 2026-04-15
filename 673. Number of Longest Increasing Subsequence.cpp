class Solution {
  public:
    int findNumberOfLIS(vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        int mxLen = 1, total = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(arr[j] < arr[i] && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];
                }
                else if(arr[j] < arr[i] && dp[j] + 1 == dp[i]){
                    cnt[i] += cnt[j];
                }
                if(mxLen < dp[i]){
                    mxLen = dp[i];
                }
            }    
        }
        
        for(int i = 0; i < n; i++){
            if(dp[i] == mxLen){
                total += cnt[i];
            }
        }
        
        return total;
    }
};