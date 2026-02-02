class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> dp(m);
        int sum = 0;
        for(int j = 0; j < m; j++){
            sum += grid[0][j];
            dp[j] = sum;
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                int up = dp[j];
                int left = j-1 >= 0 ? dp[j-1] : INT_MAX/2;
                dp[j] = min(up, left) + grid[i][j];
            }
        }

        return dp[m-1];
    }
};
