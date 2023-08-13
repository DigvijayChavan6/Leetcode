

//     User Accepted: 14128
//     User Tried: 15690
//     Total Accepted: 14598
//     Total Submissions: 26356
//     Difficulty: Easy

// You are given a 0-indexed integer array nums. You have to find the maximum sum of a pair of numbers from nums such that the

// maximum digit in both numbers are equal.

// Return the maximum sum or -1 if no such pair exists.

 

// Example 1:

// Input: nums = [51,71,17,24,42]
// Output: 88
// Explanation: 
// For i = 1 and j = 2, nums[i] and nums[j] have equal maximum digits with a pair sum of 71 + 17 = 88. 
// For i = 3 and j = 4, nums[i] and nums[j] have equal maximum digits with a pair sum of 24 + 42 = 66.
// It can be shown that there are no other pairs with equal maximum digits, so the answer is 88.

// Example 2:

// Input: nums = [1,2,3,4]
// Output: -1
// Explanation: No pair exists in nums with equal maximum digits.

 

// Constraints:

//     2 <= nums.length <= 100
//     1 <= nums[i] <= 104

class Solution
{
public:
    int maxSum(vector<int> &nums)
    {
        int mx = -1;
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            int t = nums[i], m = 0;
            while (t != 0)
            {
                int r = t % 10;
                if (m < r)
                    m = r;
                t = t / 10;
            }
            mp[i] = m;
        }
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (mp[i] == mp[j])
                    if (mx < nums[i] + nums[j])
                        mx = nums[i] + nums[j];
            }
        }
        return mx;
    }
};