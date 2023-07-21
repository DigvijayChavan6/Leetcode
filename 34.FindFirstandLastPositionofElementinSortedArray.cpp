// Given an array of integers nums sorted in non - decreasing order, find the starting and ending position of a given target value.

//                                                                   If target is not found in the array,
//     return [ -1, -1 ].

//            You must write an algorithm with
//            O(log n) runtime complexity.

//            Example 1 :

//     Input : nums = [ 5, 7, 7, 8, 8, 10 ],
//             target = 8 Output : [ 3, 4 ]

//                                 Example 2 :

//     Input : nums = [ 5, 7, 7, 8, 8, 10 ],
//             target = 6 Output : [ -1, -1 ]

//                                 Example 3 :

//     Input : nums = [],
//             target = 0 Output : [ -1, -1 ]

//                                 Constraints :

//                                 0 <= nums.length <= 105 - 109 <=
//                                 nums[i] <= 109 nums is a non - decreasing array.- 109 <= target <= 109
// ANSWER->
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int t)
    {
        vector<int> vec(2, -1);
        int r = nums.size() - 1, l = 0, mid;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (nums[mid] >= t)
                r = mid - 1;
            else
                l = mid + 1;
        }
        if (l < nums.size() && nums[l] == t)
            vec[0] = l;
        else
            return vec;
        r = nums.size() - 1;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (nums[mid] <= t)
                l = mid + 1;
            else
                r = mid - 1;
        }
        vec[1] = r;
        return vec;
    }
};