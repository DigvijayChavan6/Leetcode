/*
Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

 

Example 1:

Input: nums = [1,2,3]
Output: 6
Example 2:

Input: nums = [1,2,3,4]
Output: 24
Example 3:

Input: nums = [-1,-2,-3]
Output: -6
 

Constraints:

3 <= nums.length <= 104
-1000 <= nums[i] <= 1000
*/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums[nums.size()-1]<0)return nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3];
        if(nums[nums.size()-2]*nums[nums.size()-3]<nums[0]*nums[1]){
        return nums[nums.size()-1]*nums[0]*nums[1];
    }
    return nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3];
    }
};