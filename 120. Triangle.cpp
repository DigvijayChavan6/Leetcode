class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int n = tri.size();
        vector<int> dp(n);
        
        for(int j = 0; j < n; j++){
            dp[j] = tri[n-1][j];
        }

        for(int i = n-2; i >= 0; i--){
            vector<int> temp(i+1);
            for(int j = i; j >= 0; j--){
                temp[j] = min(dp[j], dp[j+1]) + tri[i][j];
            }
            dp = temp;
        }

        return dp[0];    
    }
};