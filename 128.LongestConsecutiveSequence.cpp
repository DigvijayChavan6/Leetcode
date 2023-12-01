// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

 

// Example 1:

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
// Example 2:

// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9
 

// Constraints:

// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size=nums.size();
        if(size==0)return 0;
        sort(nums.begin(),nums.end());
        int mx=1,cnt=1,value=nums[0];
        for(int i=1;i<size;i++){
            if(value+1==nums[i]){
                cnt++;
                value++;
            }
            else if(value != nums[i]){
                cnt=1;
                value=nums[i];
            }
            mx=max(mx,cnt);
        }
        return mx;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int size=nums.size();
        if(size==0)return 0;
        for(int i=0;i<size;i++)st.insert(nums[i]);
        int mx=0,cnt=0,minimum=INT_MIN;
        for(auto it : st){
            int x=it;
            if(st.find(x-1)==st.end()){
                cnt=1;
                minimum=x;
                while(st.find(x+1) != st.end()){
                    cnt++;
                    ++x;
                }
                mx=max(mx,cnt);
            }
        }
        return mx;
    }
};
