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


class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                if(i == j)dp[n-1][i][j] = grid[n-1][j];
                else dp[n-1][i][j] = grid[n-1][i] + grid[n-1][j];
            }
        }
        
        for(int i = n-2; i >= 0; i--){
            for(int j1 = 0; j1 < m; j1++){
                for(int j2 = 0; j2 < m; j2++){
                    int mx = INT_MIN / 2;
                    for(int a = -1; a < 2; a++){
                        for(int b = -1; b < 2; b++){
                            
                            int c1 = j1 + a;
                            int c2 = j2 + b;
                            
                            if(c1 < 0 || c2 < 0 || c1 >= m || c2 >= m){
                                continue;
                            }
                            
                            int sum = dp[i+1][c1][c2];
                            
                            sum += grid[i][j1];
                            
                            if(j1 != j2){
                                sum += grid[i][j2];
                            }
    
                            mx = max(sum, mx);
                        }
                    }
                    dp[i][j1][j2] = mx;
                }
            }
        }
        
        return dp[0][0][m-1];
    }
};