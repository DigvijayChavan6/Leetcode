// Given an integer array nums, return the length of the longest strictly increasing 
// subsequence
// .

 

// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4
// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1
 

// Constraints:

// 1 <= nums.length <= 2500
// -104 <= nums[i] <= 104
 

// Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int mx = 0;
        int n = nums.size();
        vector<int> dp(n, 0);
        for(int i=0; i<n; i++){
            dp[i] = 1;
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<i; ++j){
                if(nums[i]>nums[j] && dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                }
            }
        }
        for(int val : dp){
            mx = max(mx, val);
        }
        return mx;
    }
};