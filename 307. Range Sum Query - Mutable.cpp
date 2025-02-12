// Given an integer array nums, handle multiple queries of the following types:

// Update the value of an element in nums.
// Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
// Implement the NumArray class:

// NumArray(int[] nums) Initializes the object with the integer array nums.
// void update(int index, int val) Updates the value of nums[index] to be val.
// int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
 

// Example 1:

// Input
// ["NumArray", "sumRange", "update", "sumRange"]
// [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
// Output
// [null, 9, null, 8]

// Explanation
// NumArray numArray = new NumArray([1, 3, 5]);
// numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
// numArray.update(1, 2);   // nums = [1, 2, 5]
// numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
 

// Constraints:

// 1 <= nums.length <= 3 * 104
// -100 <= nums[i] <= 100
// 0 <= index < nums.length
// -100 <= val <= 100
// 0 <= left <= right < nums.length
// At most 3 * 104 calls will be made to update and sumRange.

class NumArray {
    vector<int> seg;
    vector<int> num;
    int n;

    void build(int root, int i, int j){
        if(i == j){
            seg[root] = num[i];
            return ;
        }
        int mid = i + (j-i)/2;
        build(2*root+1, i, mid);
        build(2*root+2, mid+1, j);
        seg[root] = seg[2*root+1] + seg[2*root+2];
    }

    int getRangeSum(int root, int i, int j, int l, int r){
        if(r < i || l > j){
            return 0;
        }
        if(i >= l && j <= r){
            return seg[root];
        }
        int mid = i + (j-i)/2;
        int lt = getRangeSum(root*2+1, i, mid, l, r);
        int rt = getRangeSum(root*2+2, mid+1, j, l, r);
        return lt+rt;
    }

    void upd(int root, int i, int j, int ind, int val){
        if(i == j){
            seg[root] = val;
            return ;
        }
        int mid = i + (j-i)/2;
        if(ind <= mid){
            upd(root*2+1, i, mid, ind, val);
        }else{
            upd(root*2+2, mid+1, j, ind, val);
        }
        seg[root] = seg[root*2+1] + seg[root*2+2];
    }

public:
    NumArray(vector<int>& nums) {
        num = nums;
        n = nums.size();
        seg.resize(num.size() * 4);
        build(0, 0, n-1);
    }
    
    void update(int index, int val) {
        upd(0, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return getRangeSum(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */