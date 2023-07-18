// You are given an integer array nums consisting of n elements, and an integer k.

// Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

 

// Example 1:

// Input: nums = [1,12,-5,-6,50,3], k = 4
// Output: 12.75000
// Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

// Example 2:

// Input: nums = [5], k = 1
// Output: 5.00000

 

// Constraints:

//     n == nums.length
//     1 <= k <= n <= 105
//     -104 <= nums[i] <= 104
// ANSWER->
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg,max=0;
        double sum=0;
        for(int i=0;i<k;i++){
            sum=nums[i]+sum;
        }
        avg=(sum/k);
        max=avg;
        for(int i=1;i<nums.size()-k;i++){
            sum=sum-nums[i-1]+nums[i+k-1];
            avg=sum/k;
            if(max<avg){
                max=avg;
            }
        }
        int op=k;
        sum=0;
        for(int i=nums.size()-1;i>=0;i--){
            if(op==0){
                break;
            }
            sum=nums[i]+sum;
            op--;
        }
        avg=sum/k;
        if(max<avg){
            max=avg;
        }
        return max;
    }
};
