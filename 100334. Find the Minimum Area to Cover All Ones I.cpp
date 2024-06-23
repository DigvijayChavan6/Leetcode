// You are given a 2D binary array grid. Find a rectangle with horizontal and vertical sides with the smallest area, such that all the 1's in grid lie inside this rectangle.

// Return the minimum possible area of the rectangle.

 

// Example 1:

// Input: grid = [[0,1,0],[1,0,1]]

// Output: 6

// Explanation:

// The smallest rectangle has a height of 2 and a width of 3, so it has an area of 2 * 3 = 6.

// Example 2:

// Input: grid = [[0,0],[1,0]]

// Output: 1

// Explanation:

// The smallest rectangle has both height and width 1, so its area is 1 * 1 = 1.

 

// Constraints:

//     1 <= grid.length, grid[i].length <= 1000
//     grid[i][j] is either 0 or 1.
//     The input is generated such that there is at least one 1 in grid.

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int row=grid.size(), col=grid[0].size();
        int left=0, right=0, up=0, down=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 1){
                    up=i+1;
                    break;
                }
            }
            if(up)break;
        }
        for(int i=row-1;i>=0;i--){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 1){
                    down=i+1;
                    break;
                }
            }
            if(down)break;
        }
        for(int i=0;i<col;i++){
            for(int j=0;j<row;j++){
                if(grid[j][i] == 1){
                    left=i+1;
                    break;
                }
            }
            if(left)break;
        }
        for(int i=col-1;i>=0;i--){
            for(int j=0;j<row;j++){
                if(grid[j][i] == 1){
                    right=i+1;
                    break;
                }
            }
            if(right)break;
        }
        int h=down-up+1, b=right-left+1;
        return h*b;
    }
};