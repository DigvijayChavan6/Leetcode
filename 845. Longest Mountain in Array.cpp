class Solution {
public:
    int longestMountain(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)return 0;
        vector<int> dp1(n, 1), dp2(n, 1);
        
        for(int i = 1; i < n; i++){
            //for(int j = 0; j < i; j++){
                if(nums[i] > nums[i-1] && dp1[i-1] + 1 > dp1[i]){
                    dp1[i] = 1 + dp1[i-1];
                }
            //}
        }
        
        for(int i = n-2; i >= 0; i--){
            //for(int j = n-1; j > i; j--){
                if(nums[i] > nums[i+1] && dp2[i+1] + 1 > dp2[i]){
                    dp2[i] = 1 + dp2[i+1];
                }
           // }
        }
        
        int maxLen = 0;
        
        for(int i = 0; i < n; i++){
            if(dp1[i] != 1 && dp2[i] != 1){
                maxLen = max(maxLen, dp1[i] + dp2[i] - 1);
            }
        }
        
        return maxLen;        
    }
};