class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> answer(n, -1);

        for(int i = n-1; i >= 0; i--)st.push(nums[i]);

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums[i]){
                st.pop();
            }
            if(st.empty())answer[i] = -1;
            else answer[i] = st.top();
            
            st.push(nums[i]);
        }

        return answer;
    }
};