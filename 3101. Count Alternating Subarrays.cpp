// You are given a
// binary array
// nums.

// We call a
// subarray
// alternating if no two adjacent elements in the subarray have the same value.

// Return the number of alternating subarrays in nums.

 

// Example 1:

// Input: nums = [0,1,1,1]

// Output: 5

// Explanation:

// The following subarrays are alternating: [0], [1], [1], [1], and [0,1].

// Example 2:

// Input: nums = [1,0,1,0]

// Output: 10

// Explanation:

// Every subarray of the array is alternating. There are 10 possible subarrays that we can choose.

 

// Constraints:

//     1 <= nums.length <= 105
//     nums[i] is either 0 or 1.

class Solution
{
public:
    long long countAlternatingSubarrays(vector<int> &nums)
    {
        long long count = 0;
        int c = 0, i;
        int size = nums.size();
        for (i = 1; i < size; i++)
        {
            if (nums[i] == nums[i - 1])
            {
                long long n = i - c;
                c = i;
                count += (n * (n + 1)) / 2;
                count -= n;
            }
        }
        long long n = i - c;
        c = i;
        count += (n * (n + 1)) / 2;
        count -= n;
        return count + size;
        // long long count = 0;
        // int size = nums.size();
        // count += size;
        // for(int i=0;i<size-1;i++){
        //     for(int j=i+1;j<size;j++){
        //         if(nums[j-1] == nums[j])break;
        //         count++;
        //     }
        // }
        // return count;
    }
};