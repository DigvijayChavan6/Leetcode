// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

// Example 1:

// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
// Example 2:

// Input: nums = [1,2,3,5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.
 

// Constraints:

// 1 <= nums.length <= 200
// 1 <= nums[i] <= 100
 
class Solution {
public:
    vector<vector<int>> dp;
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int val : nums)sum += val;
        if(sum%2 == 1)return false;

        sum /= 2;
        dp.assign(nums.size()+1, vector<int>(sum+1, -1));
        return canMakeSum(sum, nums, nums.size()-1);
    }

    bool canMakeSum(int sum, vector<int>& nums, int n){
        if(sum == 0)return true;
        if(n < 0 || sum < 0)return false;
        if(dp[n][sum] != -1)return dp[n][sum];
        bool take = canMakeSum(sum-nums[n], nums, n-1);
        bool notTake = canMakeSum(sum, nums, n-1);

        return dp[n][sum] = take || notTake;
    }
};
// Time Complexity: O(n*sum)
// Space Complexity: O(n*sum)
// where n is the size of the array and sum is the target sum we are trying to