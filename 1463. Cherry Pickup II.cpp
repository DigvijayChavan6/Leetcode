class Solution {
    int getMax(vector<vector<int>> &grid, int r, int c1, int c2, int n, int m,
                vector<vector<vector<int>>> &dp){
        if(r >= n || c1 >= m || c2 >= m || r < 0 || c1 < 0 || c2 < 0){
            return INT_MIN / 2;
        }
        if(r == n-1){
            if(c1 == c2){
                return grid[r][c1];
            }else{
                return grid[r][c1] + grid[r][c2];
            }
        }

        if(dp[r][c1][c2] != -1)return dp[r][c1][c2];

        int mx = INT_MIN/2;

        int a[] = {-1, 0, 1};
        
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                mx = max(mx, getMax(grid, r+1, c1+a[i], c2+a[j], n, m, dp));
            }
        }

        mx += grid[r][c1];

        if(c1 != c2){
            mx += grid[r][c2];
        }
        return dp[r][c1][c2] = mx;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return getMax(grid, 0, 0, m-1, n, m, dp);
    }
};