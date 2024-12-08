// You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.

 

// Example 1:

// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3
// Example 2:

// Input: nums = [1], target = 1
// Output: 1
 

// Constraints:

// 1 <= nums.length <= 20
// 0 <= nums[i] <= 1000
// 0 <= sum(nums[i]) <= 1000
// -1000 <= target <= 1000

class Solution {

    // int getCount(vector<int> &nums, int target, int index, int curSum){

    //     if(index == nums.size()){
    //         return (curSum == target) ? 1 : 0;
    //     }

    //     int add = getCount(nums, target, index+1, curSum+nums[index]);
    //     int sub = getCount(nums, target, index+1, curSum-nums[index]);
    //     return add + sub;
    // }
    

    int total;
    int getCount(vector<int> &nums, int target, int index, int sum, 
    vector<vector<int>> &memo){
        if(index == nums.size()){
            return (target == sum) ? 1 : 0;
        }
        if(memo[index][sum+total] != -1){
            return memo[index][sum+total];
        }
        int add = getCount(nums, target, index+1, sum+nums[index], memo);
        int sub = getCount(nums, target, index+1, sum-nums[index], memo);
        memo[index][sum+total] = add+sub;
        return memo[index][sum+total];
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        total = 0;
        for(int val : nums)total += val;
        vector<vector<int>> memo(nums.size()+1, vector<int>(total*2+1, -1));
        return getCount(nums, target, 0, 0, memo);
        // return getCount(nums, target, 0, 0);
    }
};