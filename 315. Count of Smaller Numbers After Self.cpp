// Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].

 

// Example 1:

// Input: nums = [5,2,6,1]
// Output: [2,1,1,0]
// Explanation:
// To the right of 5 there are 2 smaller elements (2 and 1).
// To the right of 2 there is only 1 smaller element (1).
// To the right of 6 there is 1 smaller element (1).
// To the right of 1 there is 0 smaller element.
// Example 2:

// Input: nums = [-1]
// Output: [0]
// Example 3:

// Input: nums = [-1,-1]
// Output: [0,0]
 

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> count;
        vector<int> temp(nums);

        sort(temp.begin(), temp.end());

        for(int i = 0; i < nums.size(); i++){
            int low = 0, high = nums.size()-1, mid, ind = 0;
            while(low <= high){
                mid = low + (high-low)/2;
                if(temp[mid] == nums[i]){
                    ind = mid;
                    high = mid-1;
                }else if(temp[mid] > nums[i]){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
            temp.erase(temp.begin()+ind);
            count.push_back(ind);
        }

        return count;
    }
};