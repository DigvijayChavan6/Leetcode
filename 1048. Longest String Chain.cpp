class Solution {
    bool isMatch(string &a, string &b){
        int m = a.size(), n = b.size();
        if(m != n + 1)return false;
        int i = 0, j = 0;
        while(i < m){
            if(a[i] == b[j]){
                i++; j++;
            }else{
                i++;
            }
        }
        return i == m && j == n;
    }
    static bool comp(string &s1, string &s2){
        return s1.size() < s2.size();
    }
public:
    int longestStrChain(vector<string>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1);
        int maxLen = 0;
        sort(arr.begin(), arr.end(), comp);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(isMatch(arr[i], arr[j])){
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                    }
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        
        return maxLen;        
    }
};