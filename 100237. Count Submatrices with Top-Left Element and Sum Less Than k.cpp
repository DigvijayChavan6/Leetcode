// You are given a 0-indexed integer matrix grid and an integer k.

// Return the number of submatrices that contain the top-left element of the grid, and have a sum less than or equal to k.

 

// Example 1:


// Input: grid = [[7,6,3],[6,6,1]], k = 18
// Output: 4
// Explanation: There are only 4 submatrices, shown in the image above, that contain the top-left element of grid, and have a sum less than or equal to 18.
// Example 2:


// Input: grid = [[7,2,9],[1,5,0],[2,6,6]], k = 20
// Output: 6
// Explanation: There are only 6 submatrices, shown in the image above, that contain the top-left element of grid, and have a sum less than or equal to 20.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= n, m <= 1000
// 0 <= grid[i][j] <= 1000
// 1 <= k <= 109

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int cnt=0;
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>> vec(r+1,vector<int>(c+1,0));
        for(int i=1;i<=r;i++){
            int sum=0;
            for(int j=1;j<=c;j++){
                sum+=grid[i-1][j-1];
                vec[i][j]=vec[i-1][j]+sum;
                if(vec[i][j]<=k){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};