class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, mx = 0;
        int n = s.size();        

        int last[257];

        for(int i = 0; i < 257; i++)last[i] = -1;

        for(int right = 0; right < n; right++){
            if(last[s[right]] != -1){
                left = max(left, last[s[right]] + 1);
            }
            last[s[right]] = right;
            mx = max(mx, right - left + 1);
        }

        return mx;
    }
};