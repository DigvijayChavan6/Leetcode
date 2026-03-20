
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index = 0;
        int l = 0, r = nums.size() - 1;

        while(l <= r){
            int mid = l + (r-l)/2;
            if(target == nums[mid]){
                return mid;
            }else if(nums[mid] < target){
                l = mid + 1;
                index = l;
            }else{
                r = mid - 1;
            }
        }

        return index;
    }
};